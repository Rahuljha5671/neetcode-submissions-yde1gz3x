class Solution {
public:
   
    // void solve(int i,int j,int index,vector<vector<char>>& board, string word,bool &ans,vector<vector<int>>&visited){
    //     if(index==word.size()){
    //         ans=true;
    //         return;
    //     }
    //     if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || visited[i][j]==1) {
    //         return;
    //     }
    //     visited[i][j]=1;

    //     //down
    //     solve(i+1,j,index+1,board,word,ans,visited);
    //     //up
    //     solve(i-1,j,index+1,board,word,ans,visited);
    //     //right
    //     solve(i,j+1,index+1,board,word,ans,visited);
    //     //left
    //     solve(i,j-1,index+1,board,word,ans,visited);

    //     visited[i][j]=0;

    // }

    bool isSafe(int i, int j, int n, int m, vector<vector<int>>& visited) {
        return (i >= 0 && j >= 0 && i < n && j < m && visited[i][j] == 0);
    }

    void dfs(int i, int j, int index,
             vector<vector<char>>& board,
             string& word,
             vector<vector<int>>& visited,
             bool &ans) {

        if (ans) return; // 🔥 early stop

        // ❌ mismatch
        if (board[i][j] != word[index]) return;

        // ✅ last character matched
        if (index == word.size() - 1) {
            ans = true;
            return;
        }

        visited[i][j] = 1;

        int n = board.size();
        int m = board[0].size();

        // explore 4 directions
        if (isSafe(i+1, j, n, m, visited))
            dfs(i+1, j, index+1, board, word, visited, ans);

        if (isSafe(i-1, j, n, m, visited))
            dfs(i-1, j, index+1, board, word, visited, ans);

        if (isSafe(i, j+1, n, m, visited))
            dfs(i, j+1, index+1, board, word, visited, ans);

        if (isSafe(i, j-1, n, m, visited))
            dfs(i, j-1, index+1, board, word, visited, ans);

        visited[i][j] = 0; // 🔄 backtrack
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

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         solve(i,j,0,board,word,ans,visited);
        //     }
        // }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,0,board,word,visited,ans);
            }
        }

        return ans;

        
        
    }
};
