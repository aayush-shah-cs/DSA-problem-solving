class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int to_remove = (5*n)/100;

        sort(arr.begin(),arr.end());
        double sum = 0;

        for(int i=to_remove;i< n-to_remove ;i++){
            sum += arr[i];
        }
        int m = n - 2*to_remove;
        return sum/m;
    }
};