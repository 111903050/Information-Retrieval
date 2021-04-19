#ifndef TRY1_H_INCLUDED
#define TRY1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.

typedef struct dnode{
    char data[50];
    struct dnode *next;
    struct dnode *prev;
    int counter;
}dnode;
typedef struct dlist{
    struct dnode *head;
    struct dnode *tail;
    int size;
}dlist;
typedef struct dlist *dlist_ptr;
int BinarySearch(struct dlist *,char data[]);
struct dnode *MidPointer(struct dnode *start,struct dnode *last);
int showCount(struct dlist *node);
int sWordCount(struct dlist *L,char data[]);
dlist_ptr init_list(struct dlist *);
void init();
int getSize(struct dlist *L);
void insert_head(struct dlist *, char data[]);
void insert_tail(struct dlist *,char data[]);
void insert_dlist(struct dlist *,char data[]);
void insert_pos(struct dlist *,char data[]);
void display(struct dlist *);
int getNodeby_Value(struct dlist *,char array[]);
void stopWords(int,struct dlist *);

typedef struct docnode{
    char docname[50];
    int docid;
    int size;
    struct docnode* next;
    struct dlist* L;
    int relevance;
}docnode;
typedef struct doclist{
    docnode *head;
    int docnum;
}doclist;
typedef struct doclist *doclist_ptr;
void getsize_all(struct doclist *d);
void createDoclist(struct doclist *, struct dlist *);
struct dlist* create_fp(struct doclist *,struct dlist *,char *docname);
void insert_docnames(struct doclist *d,struct dlist *, char *docname);
doclist_ptr init_doclist(struct doclist *);
int Relevance(doclist *d);
void find_query(struct doclist *d,char query[20]);

int readline(char *arr, int len) ;

#endif // TRY1_H_INCLUDED
