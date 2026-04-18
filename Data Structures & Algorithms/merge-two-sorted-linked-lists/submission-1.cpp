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

        ListNode* ansHead=NULL;
        ListNode* ansPtr=NULL;

        

        while(list1!=NULL && list2!=NULL){

            if(ansHead==NULL){
                if(list1->val>list2->val){
                    ansHead=list2;
                    list2=list2->next;
                }
                else{
                    ansHead=list1;
                    list1=list1->next;
                }
                ansPtr=ansHead;
            }
            else{
                if(list1->val<list2->val){
                    ansPtr->next=list1;
                    list1=list1->next;
                }
                else{
                    ansPtr->next=list2;
                    list2=list2->next;
                }
                ansPtr=ansPtr->next;
            }
        }

        if(list1!=NULL){
            ansPtr->next=list1;
        }

        if(list2!=NULL){
            ansPtr->next=list2;
        }

        return ansHead;
 
    }
};
