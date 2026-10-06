// class Solution {
// public:
//     void dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
//         if(i >= n || j >= m || i<0||j<0 || grid[i][j] == 0) return;

//         grid[i][j] = 0;
//         dfs(i+1,j,n,m,grid);
//         dfs(i-1,j,n,m,grid);
//         dfs(i,j+1,n,m,grid);
//         dfs(i,j-1,n,m,grid);
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         // vector<vector<bool>> vis(n,vector<bool>(m,false));
//         for(int i=0;i<n;i++){
//             // grid[i][0]=0;
//             // grid[i][n-1]=0;
//             dfs(i,0,n,m,grid);
//             dfs(i,n-1,n,m,grid);
//         }
//         for(int i=0;i<m-1;i++){
//             // grid[0][i]=0;
//             // grid[m-1][i]=0;
//             dfs(0,i,n,m,grid);
//             dfs(m-1,i,n,m,grid);
//         }
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j] == 1) count++;
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:

    void dfs(int i, int j, int n, int m,
             vector<vector<int>>& grid) {

        if(i < 0 || i >= n ||
           j < 0 || j >= m ||
           grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;

        dfs(i + 1, j, n, m, grid);
        dfs(i - 1, j, n, m, grid);
        dfs(i, j + 1, n, m, grid);
        dfs(i, j - 1, n, m, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for(int j = 0; j < m; j++) {
            dfs(0, j, n, m, grid);
            dfs(n - 1, j, n, m, grid);
        }

        for(int i = 0; i < n; i++) {
            dfs(i, 0, n, m, grid);
            dfs(i, m - 1, n, m, grid);
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};