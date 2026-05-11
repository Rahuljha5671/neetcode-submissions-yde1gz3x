class Solution {
public:
    bool solve(int i,int j,int k,string s1, string s2,string s3){
        if(k==s3.length()){
            return (i==s1.length()) && (j==s2.length());
        }

        if(i<s1.length() && s1[i]==s3[k]){
            if(solve(i+1,j,k+1,s1,s2,s3)){
                return true;
            }
        }

        if(j<s2.length() && s2[j]==s3[k]){
            if(solve(i,j+1,k+1,s1,s2,s3)){
                return true;
            }
        }

        return false;
    }

     bool solve1(int i,int j,int k,vector<vector<int>>&dp,string s1, string s2,string s3){
        if(k==s3.length()){
            return (i==s1.length()) && (j==s2.length());
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i<s1.length() && s1[i]==s3[k]){
            if(solve1(i+1,j,k+1,dp,s1,s2,s3)){
                dp[i+1][j]=1;
                return true;
            }
        }

        if(j<s2.length() && s2[j]==s3[k]){
            if(solve1(i,j+1,k+1,dp,s1,s2,s3)){
                dp[i][j+1]=1;
                return true;
            }
        }

        dp[i][j]=0;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        //bool ans=solve(0,0,0,s1,s2,s3);
        int m=s1.size();
        int n=s2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        bool ans=solve1(0,0,0,dp,s1,s2,s3);
        return ans;
        
    }
};
