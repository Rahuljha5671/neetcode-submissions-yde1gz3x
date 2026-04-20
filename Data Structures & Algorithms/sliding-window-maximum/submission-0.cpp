class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n=nums.size();

        vector<int>ans;

        for(int i=0;i<=n-k;i++){
            int maxi=INT_MIN;
            for(int j=0;j<k;j++){
                maxi=max(nums[i+j],maxi);
            }
            ans.push_back(maxi);
        }

        return ans;


        
    }
};
