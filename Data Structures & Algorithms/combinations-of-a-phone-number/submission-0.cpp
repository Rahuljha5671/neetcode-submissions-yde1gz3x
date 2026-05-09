class Solution {
public:
    void solve(string digits,int index,string output,unordered_map<char,string>&mp,vector<string>&ans){

        if(index==digits.size()){
            ans.push_back(output);
            return;
        }
        char ch=digits[index];
        string code=mp[ch];

        for(int i=0;i<code.size();i++){
            output.push_back(code[i]);
            solve(digits,index+1,output,mp,ans);
            output.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        unordered_map<char,string>mp;
        vector<string>str={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        for(int i=2;i<=9;i++){
            mp[i+'0']=str[i-2];
        }
        vector<string>ans;
        solve(digits,0,"",mp,ans);
        return ans;
        
    }
};
