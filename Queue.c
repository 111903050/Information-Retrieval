#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Queue.h"
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.

/// A node pointer implementation of queue.
/// The Queue ADT is implemented for enqueing the separated words given by user as a query.

// Function to initialize the queue.

void init_QUEUE(queue_ptr *q){
    *q=(Queue *)malloc(sizeof(Queue));
    (*q)->front=NULL;
    (*q)->rear=NULL;
}

// function checking the queue is empty or not.

int isempty(queue_ptr q){
    if(q->front==NULL && q->rear==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to add words in a queue.

void enqueue(queue_ptr q, char data[20]){
    QNode *nn=(QNode *)malloc(sizeof(QNode));
    nn->next=NULL;
    strcpy(nn->n,data);
    if(q->rear==NULL){
        q->front=q->rear=nn;
        return;
    }
    q->rear->next=nn;
    q->rear=nn;
}

// Function to dequeue the word form queue.
// it returns the dequeued word from queue.

char * dequeue(queue_ptr q){
    if(q->front==NULL){
        return 0;
    }
    struct QNode *temp=q->front;
    q->front=q->front->next;
    return temp->n;
    if (q->front==NULL){
        q->rear=NULL;
    }
}

//Function for printing the queue elements.

void printQUEUE(queue_ptr q){
    if (q->front==NULL){
        return;
    }
    struct QNode *temp=q->front;
    while(temp!=q->rear){
        printf("%s\n",temp->n);
        temp=temp->next;
    }
    printf("%s\n",temp->n);
}
