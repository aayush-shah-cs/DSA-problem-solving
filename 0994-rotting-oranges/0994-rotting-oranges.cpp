class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //concept of multi sourcse BFS
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        queue<pair<pair<int,int>,int>> q; // ({{i,j},0})
        // we storing all the occurence of the 2 in the grid and will perform multi source BFS
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 2)
                    q.push({{i,j},0});

        
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans,time);

            if(i-1 >= 0 && grid[i-1][j] == 1 && !vis[i-1][j]){
                q.push({{i-1,j},time+1});
                vis[i-1][j] = true;
            }
            if(i+1 < n && grid[i+1][j] == 1 && !vis[i+1][j]){
                q.push({{i+1,j},time+1});
                vis[i+1][j] = true;
            }
            if(j-1 >= 0 && grid[i][j-1] == 1 && !vis[i][j-1]){
                q.push({{i,j-1},time+1});
                vis[i][j-1] = true;
            }
            if(j+1 < m && grid[i][j+1] == 1 && !vis[i][j+1]){
                q.push({{i,j+1},time+1});
                vis[i][j+1] = true;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;
    }
};