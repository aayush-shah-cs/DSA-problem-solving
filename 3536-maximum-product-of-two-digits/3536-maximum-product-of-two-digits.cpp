class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n != 0){
            arr.push_back(n%10);
            n /= 10;
        }
        int ans = 0;
        for(int i=0;i<arr.size();i++){
           for(int j=i+1;j<arr.size();j++){
            ans = max(ans,arr[i]* arr[j]);
           }
        }
        return ans;
    }
};