#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};


template <typename T>
Stack<T>::Stack(){
}

template <typename T>
Stack<T>::~Stack() {
}

template <typename T>
bool Stack<T>::empty() const{ 
	return(std::vector<T>::empty()); //inherrits from std::vector
}

template <typename T>
size_t Stack<T>::size() const{ //inherrits from std::vector
	return std::vector<T>::size();
}

template <typename T> 
void Stack<T>::push(const T& item){ //inherrits from std::vector
	std::vector<T>::push_back(item);
}


template<typename T>
void Stack<T>::pop(){
	if(!empty()) { //pop
		std::vector<T>::pop_back();
	}
	else{ //if empty throw error
		throw std::underflow_error("Empty");
	}
}


template <typename T>
T const & Stack<T>::top() const {
	if(!empty()) { //return value
		return std::vector<T>::back();
	}
	else{ //if empty throw error
		throw std::underflow_error("Empty");
	}
}

#endif