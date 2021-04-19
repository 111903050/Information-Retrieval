#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "try1.h"
#include "stmr.h"
#include "Queue.h"
#include "tree.h"
#include <string.h>
#include <ctype.h>
#define MAX 100
#include "ansi_escape.h"
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.

int id;

/// This is the function which does stemming of the word.

char * assertStem(char *input) {
  char *result;
  result = strdup(input);
  result[stem(result, 0, strlen(result) - 1) + 1] = 0;
  return result;
}

/// This is the function which reads a line as a input.
/// until enter key is pressed it takes a character input from user.

int readline(char *arr, int len) {
	int k = 0;
	int ch;
	while((ch = getchar()) != '\n' && k < len - 1) {
		arr[k] = ch;
		k++;
	}
	arr[k] = '\0';
	return k;
}

/// it is the function which gives id to the document.

int getdocid(){
    return ++id;
}

/// This function returns count of a word in a file
/// Time Complexity of searching the word is O(n).
int getnodeCount(struct dlist*L,char array[20]){
    return getNodeby_Value(L,array);
}

///This function is defined for getting relevance of a query
/// it prints the files in decreasing order of relevance.
int Relevance(doclist *d){
	heap h;
	heap_init(&h);
	docnode *temp=d->head;
	while(temp){
        heap_push(&h,temp);
        temp=temp->next;
	}
	emptyPQ(&h);
	return 0;
}

///This function is for returning relevance of file to its node and store.

void find_query(struct doclist *d,char query[20]){
    struct docnode *temp=d->head;
    while(temp){
        temp->relevance=sWordCount(temp->L,query);
        temp=temp->next;
    }
}


/// This is a insert function of a singly linked list.
/// it adds files to the liked list.
void insert_docnames(struct doclist *d,struct dlist *S, char *docname){
    struct docnode *nn=(docnode *)calloc(1,sizeof(docnode));
    docnode *last=d->head;
    dlist *temp=init_list(S);
    strcpy(nn->docname,docname);
    nn->L=create_fp(d,temp,nn->docname);
    nn->size=getSize(nn->L);
    nn->docid=getdocid();
    nn->next=NULL;
    if(d->head==NULL){
        d->head=nn;
        d->docnum++;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
        d->docnum++;
    }
    last->next=nn;
    d->docnum++;
    return;
}

/// it reads the filenames from text file and recursively calls insert_docnames function to add them in linked list.

void createDoclist(struct doclist *d,struct dlist *l){
    FILE *f1=fopen("DOCNAMES.txt", "r");
    char c;
    char docname[MAX];
    int i=0;
    while(c!=EOF && i<13){
        c=fscanf(f1,"%1023s",docname);
        insert_docnames(d,l,docname);
        i++;
    }
    fclose(f1);
}

/// This function is to print the size of documents.

void getsize_all(struct doclist *d){
    struct docnode *m=d->head;
    while(m!=NULL){
        printf("The document named %s has size %d\n",m->docname,m->size);
        m=m->next;
    }
}


/// This isthe function which takes one file as an argument and make its doubly circurlar linked list.
/// it reads one by one word and then does stemming of the word.
/// At the end the word will be added to the file.

struct dlist * create_fp(struct doclist *d,struct dlist *L,char *docname){
    FILE *input;
    struct dlist *L1=0;
    input = fopen(docname, "r");
    char ch;
    char array[50];
    while(ch!=EOF){
        ch=fscanf(input,"%1023s",array);
        char *word=fixWord(array);
        char *w=assertStem(word);
        insert_dlist(L,w);
    }
    fclose(input);
    L1=L;
    printf("\e[0;33m List of File %s is created successfully\n",docname);
    printf("\e[0;0m");
    return L1;
}

/// This function will return the size of a file.
int getSize(struct dlist *L){
    return L->size;
}

///Initializing the doubly circular linked list
dlist_ptr init_list(struct dlist*L){
    L=(dlist *)malloc(sizeof(dlist));
    L->head=NULL;
    L->tail=NULL;
    L->size=0;
    return L;
}

///Initializing the singly linked list.
doclist_ptr init_doclist(struct doclist*D){
    D=(doclist *)malloc(sizeof(doclist));
    D->head=NULL;
    D->docnum=0;
    return D;
}

///Insertion at the head of doubly circular linked list.
///time complexity is O(1)
void insert_head(struct dlist * L,char data[20]){
    dnode *nn;
    nn=(dnode *)calloc(1,sizeof(dnode));
    strcpy(nn->data,data);
    if (L->head==NULL){
        L->head=L->tail=nn;
        nn->prev=L->tail;
        nn->next=L->head;
        L->size++;
        return;
    }
    else{
        if(strcmp(L->head->data,data)==0){
            L->head->counter++;
            return;
        }
        nn->next=L->head;
        L->head->prev=nn;
        nn->prev=L->tail;
        L->tail->next=nn;
        L->head=nn;
        L->size++;
        return;
    }
}

///Insertion at the tail of doubly circular linked list.
///time complexity is O(1)
void insert_tail(dlist *L,char data[20]){
    dnode *nn=(dnode *)calloc(1,sizeof(dnode));
    strcpy(nn->data,data);
    if (L->head==NULL){
        L->head=L->tail=nn;
        nn->prev=L->tail;
        nn->next=L->head;
        L->size++;
        return;
    }
    else{
        if(strcmp(L->tail->data,data)==0){
            L->tail->counter++;
            return;
        }
        nn->prev=L->tail;
        L->tail->next=nn;
        nn->next=L->head;
        L->head->prev=nn;
        L->tail=nn;
        L->size++;
        return;
    }
}

///Insertion at position of doubly circular linked list.
///time complexity is O(m)
void insert_pos(dlist *L,char data[20]){
    struct dnode *pos;
    struct dnode *temp=L->head;
    pos=(struct dnode*)calloc(1,sizeof(struct dnode));
    strcpy(pos->data,data);
    while(strcmp(data,temp->data)>0 && temp!=L->tail){
        temp=temp->next;
    }
    if(strcmp(temp->data,data)==0){
        temp->counter++;
        return;
    }
    temp=temp->prev;
    pos->prev=temp;
    pos->next=temp->next;
    temp->next->prev=pos;
    temp->next=pos;
    L->size++;
    return;
}


///This function will insert the word in doubly circular linked list alphabetically.
void insert_dlist(struct dlist *L,char data[20]){
    struct dnode *temp=L->head;
    ///if linked list is pointing to null
        if(L->head==0){
            insert_head(L,data);
            return;
        }
        while(temp==L->head || temp!=L->tail){
            //if the word entered is equal to the word already present then it will increase counter only.
            if (strcmp(data,temp->data)==0){
                temp->counter++;
                return;
            }
            //insertion at the head is alphabetically first
            if (strcmp(data,temp->data)<0){

                insert_head(L,data);
                return;
            }
            //insertion at the tail if the word is alphabetically last
            if(L->tail==L->head && strcmp(data,temp->data)>0){
                insert_tail(L,data);
                return;
            }
            //insert in between according to its alphabetical position
            if(strcmp(data,temp->data)>0 && L->head!=L->tail){
                insert_pos(L,data);
                return;
            }
            temp=temp->next;
        }
        //if all other words are not equal and it is not fitting anywhere
        //and its equal to the last word.
        //simply increase the counter
        if (strcmp(data,temp->data)==0){
            L->tail->counter++;
            return;
        }
        //else add the word to tail
        insert_tail(L,data);
}


/// Function to display the content of DCLL.
void display(struct dlist *L){
    struct dnode *temp=L->head;
    if (temp==NULL){
        return;
    }
    else{
        while(temp!=L->tail){
            printf("%s \t %d\n",temp->data,temp->counter);
            temp=temp->next;
        }
    }
    printf("%s \t %d\n",temp->data,temp->counter);
}

///Function to find counter of the word
///Time complexity O(n).
int getNodeby_Value(struct dlist *L,char array[20]){
    if (array==NULL){
        return -1;
    }
    /*for ( int i = 0; i < strlen(array); i++ )
        { array[i] = tolower( array[i] ); }
     */
    char *word=fixWord(array);
    struct dnode *temp = L->head;
    //	If temp is not equal to tail OR If there is only one element on the list --> enter the while loop
    while ( temp==L->tail || temp!=L->tail) {

        //		If there is only one element on the list AND it is not equal to word --> return zero
        if ( temp == NULL ){
                //printf("hk\n");
            return -1;
        }
        if ( strcmp(word ,temp->data)==0)
        {
            //printf("hk\n");
            return (temp->counter)+1;
        }
		//	If word is less temp, that means word is not on the list. So return zero
        if ( strcmp(word ,temp->data )<0){
            return -1;
        }
        temp = temp->next;
    }
    if ( strcmp(word , temp->data )==0){
        return temp->counter + 1;
    }
    return -1;
}


///Function to find the pointer to the middle element of LL.
struct dnode *MidPointer(struct dnode *start,struct dnode *last){
    struct dnode *slow=start;
    struct dnode *fast=start->next;
    if(start==NULL){
        return start;
    }
    while(fast!=last){
        fast=fast->next;
        if(fast!=last){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}

///Function to find counter of the word
///Time complexity O(log(n)).
int BinarySearch(struct dlist *L,char data[20]){
    struct dnode *start=L->head;
    struct dnode *last=L->tail;
    do{
        struct dnode *mid=MidPointer(start,last);
        // If middle is empty
        if (mid == NULL)
            return -1;

        // If value is present at middle
        if(strcmp(mid->data,data)==0)
            return mid->counter+1;

        // If value is more than mid
        else if (strcmp(mid->data,data)<0)
            start = mid -> next;

        // If the value is less than mid.
        else
            last = mid;

    } while (last == NULL ||
             last != start);

    // value not present
    return 0;
}

///This function splits the word fro the query given by user.
/// Enqueues the word in queue.
/// Dequeues one by one and for the single word it finds its counter in the file.
/// it adds the counter of each word and returns this value to the function.
int sWordCount(struct dlist *L,char data[MAX]){
    Queue *q;
    init_QUEUE(&q);
    char splitStrings[10][10];
    int i,j,cnt;
    j=0; cnt=0;
    for(i=0;i<=(strlen(data));i++)
    {
        if(data[i]==' '||data[i]=='\0')
        {
            splitStrings[cnt][j]='\0';
            cnt++;
            j=0;
        }
        else
        {
            splitStrings[cnt][j]=data[i];
            j++;
        }
    }
    char *ch=0;
    for(i=0;i < cnt;i++){
        ch=splitStrings[i];
        enqueue(q,ch);
    }
    char *cha=0;
    int m=0,x=0;
    for(int i=0;i<cnt;i++){
        cha=dequeue(q);
        m=BinarySearch(L,cha);
        x=x+m;
    }
    return x;
}



