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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }

        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* ansHead=NULL;
        ListNode* ansPtr=NULL;

        

        while(temp1!=NULL && temp2!=NULL){

            if(ansHead==NULL){
                if(temp1->val>temp2->val){
                    ansHead=temp2;
                    temp2=temp2->next;
                }
                else{
                    ansHead=temp1;
                    temp1=temp1->next;
                }
                ansPtr=ansHead;
            }
            else{
                if(temp1->val<temp2->val){
                    ansPtr->next=temp1;
                    temp1=temp1->next;
                }
                else{
                    ansPtr->next=temp2;
                    temp2=temp2->next;
                }
                ansPtr=ansPtr->next;
            }
        }

        if(temp1!=NULL){
            ansPtr->next=temp1;
        }

        if(temp2!=NULL){
            ansPtr->next=temp2;
        }

        return ansHead;
 
    }
};
