class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        int odd_digonal = mat[n/2][n/2];

        //left diagonal
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    sum += mat[i][j];
                }
            }
        }

        //right diagonal
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i+j == n-1){
                    sum += mat[i][j];
                }
            }
        }
        if(n%2 != 0){
            return sum - odd_digonal;
        }
        return sum;
    }
};