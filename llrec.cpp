#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
	if(head == nullptr){ //base case
		larger = nullptr;
		smaller = nullptr;
		return;
	}
	else{
		if(head->val > pivot){ //val is smaller or equal to pivot
			Node* temp = head->next;
			larger = head;
			larger->next = nullptr;
			head = temp;
			llpivot(head, smaller, larger->next, pivot);
		}
		else{										//val is larger than pivot
			Node* temp = head->next;
			smaller = head;
			smaller->next = nullptr;
			head = temp;
			llpivot(head, smaller->next, larger, pivot);
		}
	}
}
