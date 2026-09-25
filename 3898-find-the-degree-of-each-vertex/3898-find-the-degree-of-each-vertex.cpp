class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> degree;
        int n = matrix.size();
        int m = matrix[0].size();
    
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += matrix[i][j]; 
            }
            degree.push_back(sum);
        }
        return degree;
    }
};