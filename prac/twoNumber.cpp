/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *l3;
        ListNode *p3;

        int sum = 0, cin = 0, val = 0, i = 0, p1Val = 0, p2Val = 0;
        
        do{
           //set value of listNode and do while p1 and p2 are not NULL.
            
            p1Val = (p1 != NULL) ? p1->val : 0;
            p2Val = (p2 != NULL) ? p2->val : 0;
            
            sum = p1Val + p2Val + cin;
            cin = sum / 10;
            val = sum % 10;
            
            if(i == 0){
                l3 = new ListNode(val);
                p3 = l3;
            }else{
                p3->next = new ListNode(val);
                p3 = p3->next;
            }
            p1 = (p1 != NULL) ? ((p1->next == NULL) ? NULL : p1->next) : NULL;
            p2 = (p1 != NULL) ? ((p2->next == NULL) ? NULL : p2->next): NULL;
            i++;
            
        }while((p1 != NULL && p2 != NULL) || (cin != 0));
        
      return l3;
    }
};
