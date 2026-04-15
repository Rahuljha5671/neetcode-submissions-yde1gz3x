class Solution {
public:
    bool isPalindrome(string s) {

        string temp="";

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c>='A' && c<='Z'){
                c=(c-'A')+'a';
                temp+=c;
            }
            else if(c>='a' && c<='z'){
                temp+=c;
            }
            else if(c>='0' && c<='9'){
                temp+=c;
            }
        }

        bool isPalindrome=true;
        int n=temp.size();
        for(int i=0;i<n/2;i++){
            if(temp[i]!=temp[n-i-1]){
                // cout<<i<<endl;
                // cout<<s[i]<<endl;
                isPalindrome=false;
                break;
            }

        }
        // cout<<temp;

        return isPalindrome;
        
    }
};
