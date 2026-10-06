class Solution {
public:
    void dfs(int n,int m,vector<vector<int>>& image,int sr,int sc,int color,int initialColor,vector<vector<bool>>& vis){
        if(sr >= n || sc >= m || sr <0 ||sc < 0|| image[sr][sc] == color || image[sr][sc] != initialColor ||vis[sr][sc]) return ;
        vis[sr][sc] = true;
        image[sr][sc] = color;
        dfs(n,m,image,sr+1,sc,color,initialColor,vis);
        dfs(n,m,image,sr-1,sc,color,initialColor,vis);
        dfs(n,m,image,sr,sc-1,color,initialColor,vis);
        dfs(n,m,image,sr,sc+1,color,initialColor,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(n,m,image,sr,sc,color,initialColor,vis);
        return image;
    }
};