class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        //O(n*k),O(1)
        // int n=nums.size();
        // vector<int>ans;
        // for(int i=0;i<=n-k;i++){
        //     int maxi=INT_MIN;
        //     for(int j=0;j<k;j++){
        //         maxi=max(nums[i+j],maxi);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;

        int n=nums.size();
        vector<int>ans;
        deque<int>q;
        int idx;
        int maxi=INT_MIN;

        // for(int i=0;i<k;i++){
        //     if(nums[i]>maxi){
        //         maxi=nums[i];
        //         idx=i;
        //     }
            
        // }
        // q.push_back(idx);

        int i=0,j=0;

        while(j<n){

            while(!q.empty() && nums[j]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(j);

            if(j-i+1==k){
                while(!q.empty() && q.front()<i){
                    q.pop_front();
                }
                ans.push_back(nums[q.front()]);
                i++;
            }

            j++;
        }

        return ans;
    }
};
