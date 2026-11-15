class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int mod = 1e9+7;
        long long ans=0;
        long long even=1;
        long long odd=0;
        long long prefix=0;
        for(int num : arr){
            prefix += num;
            if(prefix % 2==1){
                ans = (ans+even)%mod;
                odd++;
            }
            else{
                ans = (ans+odd)%mod;
                even++;
            }
        }
        return ans;
    }
};