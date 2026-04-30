class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //m*nlogn
        // int m=strs.size();
        // vector<vector<string>>ans;
        // unordered_map<string,vector<string>>mp;

        // for(int i=0;i<m;i++){
        //     string temp=strs[i];
        //     sort(temp.begin(),temp.end());
        //     mp[temp].push_back(strs[i]);
        // }
        // for(auto it:mp){
        //     ans.push_back(it.second);
        // }
        // return ans;

        int m=strs.size();

        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        

        for(int i=0;i<m;i++){
            string temp=strs[i];
            vector<int>hash(26,0);

            for(char c:temp){
                hash[c-'a']++;
            }

            string key=to_string(hash[0]);
            for(int j=1;j<26;j++){
                key+=','+to_string(hash[j]);
            }

            mp[key].push_back(strs[i]);
        }

        for(auto it:mp){
            ans.push_back(it.second);
        }

        return ans;   
    }
};
