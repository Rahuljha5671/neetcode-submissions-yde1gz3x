class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        bool hasDup=false;

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]!=0){
                hasDup=true;
                break;
            }
            mp[nums[i]]++;
        }
        return hasDup;
        
    }
};