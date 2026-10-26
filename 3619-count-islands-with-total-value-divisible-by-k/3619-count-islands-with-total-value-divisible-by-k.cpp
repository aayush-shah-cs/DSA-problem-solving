class Solution {
public:
    long long  dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i >= n || i <0 || j >= m || j < 0 || grid[i][j] == 0 || vis[i][j]) return 0;
        vis[i][j] = true;

        long long sum = grid[i][j];
        sum += dfs(i-1,j,n,m,grid,vis);
        sum += dfs(i+1,j,n,m,grid,vis);
        sum += dfs(i,j-1,n,m,grid,vis);
        sum += dfs(i,j+1,n,m,grid,vis);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    long long sum = dfs(i,j,n,m,grid,vis);
                    if(sum % k == 0) island++;
                } 
            }
        }
        return island;
    }
};