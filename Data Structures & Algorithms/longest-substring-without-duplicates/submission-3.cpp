class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        if(n==0){
            return 0;
        }
        cout<<n;
        int res=0;

        for(int i=0;i<n;i++){
            cout<<"enter"<<endl;
            unordered_map<char,bool>visited;
            for(int j=i;j<n;j++){
                if(visited.contains(s[j])){
                    cout<<s[j]<<"space"<<endl;
                    break;
                }
                else{
                    visited[s[j]]=true;
                }
                res=max(res,j-i+1);
            }
        }

        return res;
        
        
    }
};
