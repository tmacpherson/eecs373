#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t* temp = head;
	list_t* prev = NULL;
	while((temp != NULL) && (temp->index < new_element->index)){
		prev = temp;
		temp = temp->next;
	}// end while

	if(prev != NULL){
		prev->next = new_element;
		new_element->next = temp;
	}// endif
	else{
		new_element->next = temp;
		head = new_element;
	} // end else

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* temp = head;
	list_t* post = head->next;
	head = NULL;
	while(post != NULL){
		temp->next = head;
		head = temp;
		temp = post;
		post = post->next;
	} // end while
	// now add the last one
	temp->next = head;
	head = temp;
	return head;
}

