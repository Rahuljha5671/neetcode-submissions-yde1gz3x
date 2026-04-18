/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;

       


        ListNode* temp=head;

        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

         //for first node
        if(n==size){
           return head->next;
        }
        
        //rest of the nodes
        int ptr=1;
        temp=head;

        int toDelIdx=size-n+1;  //4-2+1=3

        while(ptr!=toDelIdx-1){
            ptr++;
            temp=temp->next;
        }

        temp->next=temp->next->next;

        return head;
        
    }
};
