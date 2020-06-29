#include <iostream>

typedef struct ListNode{
    int n;
    struct ListNode* next;   
}ListNode;

using namespace std;

ListNode* oddEvenSeg(ListNode* head);
void printhead(ListNode* head);


int main(void){

	ListNode l0, l1, l2, l3, l4, l5, l6;
	l0.n = 2;
	l1.n = 1;
	l2.n = 3;
	l3.n = 5;
	l4.n = 6;
	l5.n = 4;
	l6.n = 7;

	l0.next = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = NULL;

	ListNode* li = oddEvenSeg(&l0);

	printhead(li);
}
 
/*
Input: 1->2->3->4->5->NULL
 1 3 2 4 5
Output: 1->3->5->2->4->NULL
*/
ListNode* oddEvenSeg(ListNode* head){
	ListNode* bdr = head; //the boundary of odd-even
    unsigned short i = 2; //the index : starts from 2 (0 as 1)
    ListNode* ptr = (head != NULL) ? head->next : NULL;
    ListNode* temp = ptr;
    while(ptr!= NULL && ptr->next != NULL && bdr != NULL){
        //if i is even,  left shift all elements from ptr to bdr;
        if(i % 2 == 0 ){
            bdr->next = ptr->next;
            bdr = bdr->next;
            ptr->next = bdr->next;
            bdr->next = temp;
            i++;
        }else{
            temp = bdr->next;
            ptr = ptr->next;
            i++;
        }
    }
    return head;

}


void printhead(ListNode* head){
    ListNode *ptr = head;
    while(ptr != NULL){
        printf("%d ->", ptr->n);
        ptr = ptr->next;
    }
    printf("\n");
}