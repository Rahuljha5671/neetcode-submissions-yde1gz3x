class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>freq(n+1);
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            freq[it.second].push_back(it.first);
        }


        for(int i=n;i>=0;i--){
            for(auto it:freq[i]){
                ans.push_back(it);
                if(ans.size()==k){
                    return ans;
                }
            }
        }

        return ans;



    
        
    }
};
