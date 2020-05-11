#include <iostream>
#include <cstdlib>
#include <array>


using namespace std;
#define arsize 15

typedef struct node{
    int n;
    struct node* next;
}node;


node* create(int i){
    node* x = (node*) malloc(sizeof(node));
    x->n = i;
    return x;
}

void printlist(node* head){
    node* p = head;
    while(p != NULL){
        cout << p->n << ", ";
        p = p->next;
    }
}

void createL(array<int, arsize> & ar, int i, node* cur, node* head){
    
    if(i > 0 && i < arsize){
        cur->next = create(ar[i]);
        i++;
        createL(ar, i, cur->next, head);
    }
}


int main(void){
	
	array<int, arsize>ar = {12,2,3,4, 5, 6, 7, 8,9, 10, 11, 12, 13, 14, 15};
    node* head = create(ar[0]);
    createL(ar, 1, head, head);
    printlist(head);
}	