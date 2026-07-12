class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_prof = 0;
        int best_buy = prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]>best_buy){
                max_prof = max(max_prof,prices[i] - best_buy);
            }
            best_buy = min(best_buy,prices[i]);
        }
        return max_prof;
    }
};