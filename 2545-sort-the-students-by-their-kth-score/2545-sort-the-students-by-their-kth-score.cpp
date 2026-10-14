class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // for(int i=1;i<score.size();i++){
        //     for(int j=k;j<score[0].size();j++){
        //         if(score[i][j] > score[i-1][j]){
        //             swap(score[i][j],score[i-1][j]);
        //         }
        //     }
        // }
        // return score;
        sort(score.begin(), score.end(), [k](const vector<int>& a, const vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};