class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,int n,int m){
        if(i >= n || i < 0 || j >= m || j <0 || board[i][j] != 'O') return;

            board[i][j] = '#';

            dfs(i+1,j,board,n,m);
            dfs(i-1,j,board,n,m);
            dfs(i,j-1,board,n,m);
            dfs(i,j+1,board,n,m);
        
    }
    void solve(vector<vector<char>>& board) {
        int n =board.size();
        int m = board[0].size();

        for(int i=0;i<m;i++){
            if(board[0][i] == 'O')
                dfs(0,i,board,n,m);
            if(board[n-1][i] == 'O')
                dfs(n-1,i,board,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                dfs(i,0,board,n,m);
            if(board[i][m-1] == 'O')
                dfs(i,m-1,board,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};