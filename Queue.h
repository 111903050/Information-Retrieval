#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.

typedef struct QNode{
    char n[20];
    struct QNode *next;
}QNode;

typedef struct Queue{
    struct QNode *front,*rear;
}Queue;
typedef struct Queue *queue_ptr;
void init_QUEUE(queue_ptr *q);
void enqueue(queue_ptr q,char data[]);
char * dequeue(queue_ptr q);
int isempty(queue_ptr q);
void printQUEUE(queue_ptr q);

#endif // QUEUE_H_INCLUDED
