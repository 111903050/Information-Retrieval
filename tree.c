#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.


/// The Max Heap is implemented for getting the most relevant file for the query.

//Initialize the heap

void heap_init(struct heap *h)
{
	h->count = 0;
	h->size = initial_size;
	h->heaparr = (docnode *) malloc(sizeof(docnode) * 4);
	if(!h->heaparr) {
		printf("Error allocatinga memory...\n");
		exit(-1);
	}

}

// Here we are pushing the File node  which contains the pointer to next file and pointer to the head of the list of words.
// We pushing file into heap and arranging it according to its relevance.

void heap_push(heap *h,docnode *d){
    int index, parent;
	if (h->count == h->size)
	{
		h->size += 1;
		h->heaparr = realloc(h->heaparr, sizeof(docnode) * h->size);
		if (!h->heaparr)
            exit(-1);
	}
    index = h->count++; // First insert at last of array

 	// Find out where to put the element and put it
	for(;index; index = parent)
	{
		parent = (index - 1) / 2;
		if ( h->heaparr[parent].relevance >= d->relevance)
            break;
		h->heaparr[index] = h->heaparr[parent];
	}
	h->heaparr[index] = *d;
}

//This function arranges the file according to its relavance.

void max_heapify(docnode *data, int loc, int count) {
	int left, right, largest;
	struct docnode temp;
	left = 2*(loc) + 1;
	right = left + 1;
	largest = loc;


	if (left <= count && data[left].relevance > data[largest].relevance) {
		largest = left;
	}
	if (right <= count && data[right].relevance > data[largest].relevance) {
		largest = right;
	}

	if(largest != loc) {
		temp = data[loc];
		data[loc] = data[largest];
		data[largest] = temp;
		max_heapify(data, largest, count);
	}

}

// Displays the contents of heap.

void heap_display(struct heap *h) {
	int i;
	for(i=0; i<h->count; ++i) {
		printf("|%d|", h->heaparr[i].relevance);
	}
	printf("\n");
}

//Deletes root element of heap.

void heap_delete(struct heap *h)
{
	struct docnode removed;
	struct docnode temp = h->heaparr[--h->count];


	if ((h->count <= (h->size + 2)) && (h->size > initial_size))
	{
		h->size -= 1;
		h->heaparr = realloc(h->heaparr, sizeof(docnode) * h->size);
		if (!h->heaparr)
            exit(-1); // Exit if the memory allocation fails
	}
 	removed = h->heaparr[0];
 	h->heaparr[0] = temp;
 	max_heapify(h->heaparr, 0, h->count);
 	char *ch=0;
 	ch=removed.docname;
 	printf("%s\n",ch);
}


//iteratively calls the heap delete function

int emptyPQ(struct heap *pq) {
	//int i;
	while(pq->count != 0) {
		heap_delete(pq);
	}
	return 0;
}

