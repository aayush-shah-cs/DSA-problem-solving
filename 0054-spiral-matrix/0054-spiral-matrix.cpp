class Solution {
public: 
    vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i,int j,int n,int m,vector<vector<int>>& matrix, vector<int>& ans,vector<vector<bool>>& vis,int d){
        if(i >=n || j >= m || i<0||j<0|| vis[i][j]) return;
        vis[i][j] = true;
        ans.push_back(matrix[i][j]);
        int nr = i + direction[d][0];
        int nc = j + direction[d][1];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]){
            d = (d+1)%4;
            nr = i + direction[d][0];
            nc = j + direction[d][1];
        }

        dfs(nr,nc,n,m,matrix,ans,vis,d);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        dfs(0,0,n,m,matrix,ans,vis,0);
        return ans;
    }
};