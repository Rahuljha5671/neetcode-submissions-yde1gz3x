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
    class Compare{
        public:
            bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;

        for(auto list:lists){
            pq.push(list);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* ptr=dummy;

        while(!pq.empty()){
            ListNode* top=pq.top();
            ptr->next=top;
            ptr=ptr->next;
            pq.pop();

            if(top->next){
                pq.push(top->next);
            }
        }
        return dummy->next;
        
    }
};
