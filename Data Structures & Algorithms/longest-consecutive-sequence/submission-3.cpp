class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }

        // sort(nums.begin(),nums.end());

        // int size=1;
        // int ans=1;

        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i+1]==nums[i]+1){
        //         size++;
        //     }
        //     else if(nums[i+1]==nums[i]){
        //         continue;
        //     }
        //     else{
        //         size=1;
        //     }
        //     ans=max(ans,size);
        // }

        // return ans;

        int size=0;
        int ans=0;
        map<int,int>mp;

        for(int n:nums){
            mp[n]++;
        }

        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            size=0;
            if(mp[curr-1]==0){
                while(mp[curr++]){
                    size++;
                }
                ans=max(ans,size);
            }
        }
        return ans;


        
    }
};
