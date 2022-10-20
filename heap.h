#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : comparator(c), sizeOfHeap(m){
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){
  }

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  PComparator comparator;
  std::vector<T> heapVec;
  int sizeOfHeap;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heapVec.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heapVec.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  this->heapVec.push_back(item);
	unsigned int insertIndex = this->heapVec.size() - 1;
	while(insertIndex > 0) { 
    int parentIndex = (insertIndex - 1)/ sizeOfHeap;
		if(comparator(this->heapVec[insertIndex], this->heapVec[parentIndex])){
			std::swap(this->heapVec[insertIndex], this->heapVec[parentIndex]); 
			insertIndex = parentIndex;
		}
		else{
			break;
		}
	}
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
		throw std::underflow_error("Empty!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	else{
		return this->heapVec[0]; //return the root value
	}
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){ //heap is empty, throw exception
    throw std::underflow_error("Heap is empty");
  }
  else if(heapVec.size() == 1){ //only one item, remove
    heapVec.pop_back();
    return;
  }
  else{ 
    std::swap(heapVec[heapVec.size()-1], heapVec[0]); //swap the first and last element
    heapVec.pop_back(); //pop back to remove what was the top element
    unsigned int parentIndex2 = 0;
    while(1){ //implementing trickle down
      unsigned int targetIndex = parentIndex2;
      for(unsigned int i = (parentIndex2 * sizeOfHeap) + 1; i <= std::min((parentIndex2 * sizeOfHeap) + sizeOfHeap, (unsigned int)heapVec.size() - 1); i++){
        if(comparator(heapVec[i], heapVec[targetIndex])){
          targetIndex = i;
        }
      }
      if(parentIndex2 == targetIndex) {
        break;
      }

      std::swap(heapVec[parentIndex2], heapVec[targetIndex]);
      parentIndex2 = targetIndex;
    }
  }
}



#endif

