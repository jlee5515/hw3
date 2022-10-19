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
		llpivot(head->next, smaller, larger, pivot);

		if(head->val <= pivot){ //val is smaller or equal to pivot
			head->next = smaller;
			smaller = head;
		}
		else{										//val is larger than pivot
			head->next = larger;
			larger = head;
		}
	}
}
