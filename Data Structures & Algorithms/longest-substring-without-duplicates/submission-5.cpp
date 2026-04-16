class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //     int n=s.size();
        //     int res=0;

        //     for(int i=0;i<n;i++){
        //         unordered_map<char,bool>visited;
        //         for(int j=i;j<n;j++){
        //             if(visited.contains(s[j])){
        //                 break;
        //             }
        //             else{
        //                 visited[s[j]]=true;
        //             }
        //             res=max(res,j-i+1);
        //     }
        // }
        // return res;

        int n=s.size();

        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int res=0;

        while(j<n){
            if(mp.contains(s[j])){
                i=max(mp[s[j]]+1,i);
            }

            mp[s[j]]=j;
            j++;
            res=max(res,j-i);
        }

        return res;


        
        
    }
};
