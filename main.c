#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include "try1.h"
#include "stmr.h"
#include "Queue.h"
#include "tree.h"
#include <string.h>
#include "ansi_escape.h"
#define COUNT 2048
/************** 4th Semester Project on Information Retrieval ***************/
///Github link- https://github.com/111903050/Information-Retrieval.git
/// Author - Nikhil Ajit Repale.
/// MIS- 111903050.
/// SY COMP.
/// College of Engineering, Pune.
/// Guidance- Prof. Shrida Kalamakar.

int main(){

    // This is for setting up a console to print colorfull text.
    setupConsole();

    printf("\n");
    printf("\e[4;32m************************  MINI PROJECT - Information Retrieval  **********************************\n");
    printf("\n");
    printf("\e[4;0m");
    printf("\e[0;35mAuthor----------> NIKHIL AJIT REPALE\n");
    printf("MIS-------------> 111903050\n");
    printf("SY COMP\n");
    printf("COLLEGE OF ENGINEERING PUNE\n");
    printf("-------------------------------------------------------------------\n");
    printf("\e[0;0m");
    doclist_ptr d=0;
    d=init_doclist(d);
    dlist_ptr l=0;
    l=init_list(l);
    char ch,x;

    /// This is the function which will create files list and each file will point to its list of words with
    /// their respective counters.
    createDoclist(d,l);


    do{
        printf("\nEnter the query: ");
        char str[100];
        while((x = readline(str, COUNT))){
            /// This functions will first split the queries according to space entered by user
            /// And then for each word they will return the counter in file .
            /// At the end they will add counter of each word and return it to the file.

            find_query(d,str);
            printf("\e[0;34m \n The relevance of the query is as follow \n");
            printf("\e[0;0m");

            ///This is the function which will print the file names according to relevance for the query entered by user.

            Relevance(d);
            printf("\e[4;16m\nDo You Want to continue searching on the app. (Y/N)");
            printf("\e[4;0m");
            printf("\e[4;23m\n\e[4;0m");
            scanf("%c",&ch);
        }
    }while(ch=='Y' || ch == 'y');
    restoreConsole();
}
