class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char ch:t){
            mp[ch]++;
        }

        int i=0;
        int j=0;
        int n=s.size();
        int count=mp.size();
        int start=0;
        int end=0;
        int ans=INT_MAX;
        string str="";

        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }

            //try to lower the size of the substr when we find one substr which contains all character
            while(count==0){
                if(ans>j-i+1){
                    ans=j-i+1;
                    start=i;
                    end=j;
                }

                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }

        if(ans!=INT_MAX){
            for(int k=start;k<=end;k++){
                str+=s[k];
            } 
        }

        return str; 
    }
};
