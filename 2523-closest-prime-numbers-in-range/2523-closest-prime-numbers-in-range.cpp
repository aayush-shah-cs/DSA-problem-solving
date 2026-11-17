class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        //one of approach comes in my mind is using Sieve of Eratosthenes
        int n=right+1;
        vector<bool> prime(n,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<int> ans = {-1,-1};
        int m = prime.size();
        int prev = -1;
        int mindiff = INT_MAX;
        for(int i=left;i<=right;i++){
            if(prime[i]){
                if(prev != -1 && (i-prev) < mindiff){
                    mindiff = i-prev;
                    ans={prev,i};
                }
                prev=i;
            }
        }
        return ans;
    }
};