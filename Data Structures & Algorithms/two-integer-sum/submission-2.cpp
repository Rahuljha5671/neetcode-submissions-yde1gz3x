class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        vector<int>ans;

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             return ans;
        //         }
        //     }
        // }

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]=i;                   
        }

        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(mp.contains(req) && mp[req]!=i){
                ans.push_back(i);
                ans.push_back(mp[req]);
                break;
            }
        }
        return ans;



        
    }
};
