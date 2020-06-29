/**************************
* @author Harmandeep Sandhu
* Question 3: Inserts a node into a sorted singly linked list. 
**************************/

#include <stdio.h>
//include node struct
#include "node.h"
#include <assert.h>

/*
* returns 1 if inserted, 0 if error
*/
node* insertElementIntoSortedSLList(node* list, node* element);
void printList(node* list);

int main(void){

    //linear list
    node l1, l2, l3, l4;

    l1.n = 1;
    l2.n = 8;
    l3.n = 12;
    l4.n = 20;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = NULL;

    node element;
    element.n = 11;
    element.next = NULL;

    node *newList = insertElementIntoSortedSLList(&l1, &element);
    printList(newList);

}

