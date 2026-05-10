class Solution {
public:
    bool isSafe(int i,int j,vector<vector<int>>& visited){
        int n=visited.size();
        int m=visited[0].size();

        if(i<n && j<m && i>=0 && j>=0 && visited[i][j]==0){
            return true;
        }
        return false;
    }
    void solve(int i,int j,int index,vector<vector<char>>& board, string word,bool &ans,vector<vector<int>>&visited){
        if(index==word.size()){
            ans=true;
            return;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || visited[i][j]==1) {
            return;
        }
        visited[i][j]=1;

        //down
        solve(i+1,j,index+1,board,word,ans,visited);
        //up
        solve(i-1,j,index+1,board,word,ans,visited);
        //right
        solve(i,j+1,index+1,board,word,ans,visited);
        //left
        solve(i,j-1,index+1,board,word,ans,visited);

        visited[i][j]=0;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        // vector<vector<int>>visited;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         visited[i].push_back(0);
        //     }
        // }

        vector<vector<int>> visited(n, vector<int>(m, 0));
        bool ans=false;
        string output="";

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,0,board,word,ans,visited);
            }
        }

        return ans;

        
        
    }
};
