class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";

        for(string s:strs){
            string len=to_string(s.size());
            res+=len+'#'+s;
        }

        return res;
        

    }

    vector<string> decode(string s) {
        vector<string>ans;

        if(s==""){
            return ans;
        }

        // int i=0;
        int j=0;

        // 5#Hello5#World
        // 0123456
        while(j<s.size()){
            string temp="";
            while(s[j]!='#'){
                temp+=s[j];
                j++;
            }

            int ptr=stoi(temp);
            string str=s.substr(j+1,ptr);;
            // int i;
            // for(i=j+1;i<=j+ptr;i++){
            //     str+=s[i];
            // }

            ans.push_back(str);
            j=j+ptr+1;
        }

        return ans;
    }
};
