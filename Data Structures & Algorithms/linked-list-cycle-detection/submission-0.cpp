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
    bool hasCycle(ListNode* head) {

        unordered_map<ListNode*,bool>visited;

        ListNode* temp=head;
        bool hasCycle=false;

        while(temp!=NULL){
            if(visited[temp]){
                hasCycle=true;
                break;
            }
            visited[temp]=true;
            temp=temp->next;

        }

        return hasCycle;

        
    }
};
