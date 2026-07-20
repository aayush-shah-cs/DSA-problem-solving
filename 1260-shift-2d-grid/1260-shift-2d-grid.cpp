class Solution {
public:

    void reverse(vector<int>& temp,int st,int end){
        while(st < end){
            int t = temp[st];
            temp[st] = temp[end];
            temp[end] = t;
            st++;
            end--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }
        int store = temp.size();
        k = k % store;

        reverse(temp,0,store-1);
        reverse(temp,0,k-1);
        reverse(temp,k,store-1);

        int idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = temp[idx++];
            }
        }

        return grid;
    }
};