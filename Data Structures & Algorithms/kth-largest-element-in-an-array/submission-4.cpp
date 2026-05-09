class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //kth largest mtlb k-1 se chota
        //2nd largest mtlb 2-1=1 se chota to socho agr 2 size ka min heap maintain kre to uska top bs ek ele se chota hoga aur wohi answer h hmara
        priority_queue<int,vector<int>,greater<int>>pq;

        // this was a bit complex
        // for(int i=0;i<k;i++){
        //     pq.push(nums[i]);
        // }
        // for(int i=k;i<nums.size();i++){
        //     if(!pq.empty() && nums[i]>pq.top()){
        //         if(pq.size()==k){
        //             pq.pop();
        //         }
        //         pq.push(nums[i]);
        //     }
        // }

        // return pq.top();

        //simple solution
        //agr hm k size ka minheap bna ke rkhte h to kaam hojaega

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
        
    }
};
