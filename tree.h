#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "try1.h"
#define initial_size 4
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.

typedef struct heap {
	int size;
	int count;
	docnode * heaparr;
}heap;

void heap_init(heap *h);
int emptyPQ(struct heap *pq);
void heap_delete(struct heap *h);
void heap_display(struct heap *h) ;
void max_heapify(docnode *data, int loc, int count);
void heap_push(heap *h,docnode *d);
#endif // TREE_H_INCLUDED
