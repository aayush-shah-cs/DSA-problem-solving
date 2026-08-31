class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for(auto x : s){
            if(x == '('){
                if(count > 0){
                    ans += x;
                }
                count++;
            }
            else{
                count--;
                if(count > 0){
                    ans += x;
                }
            }
        }
        return ans;
    }
};