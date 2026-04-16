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

    ListNode* insertAtHead(ListNode* newHead,ListNode * nodeToInsert){

        if(newHead==NULL){
            newHead=new ListNode(nodeToInsert->val); 
        }
        else{
            ListNode * tempNode=new ListNode(nodeToInsert->val);
            tempNode->next=newHead;
            newHead=tempNode;
        }

        return newHead;

    }
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL){
            return head;
        }

        ListNode* temp=new ListNode();

        ListNode* newHead=NULL;
        while(head!=NULL){
            newHead=insertAtHead(newHead,head);
            head=head->next;
        }

        return newHead;

       
    }
};
