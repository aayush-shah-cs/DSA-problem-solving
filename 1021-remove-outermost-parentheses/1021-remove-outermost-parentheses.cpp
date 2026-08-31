class Solution {
public:
    string removeOuterParentheses(string s) {
        int appearance = 0;
        stack<char> st;
        string ans;
        for(auto x : s){
            if(x == '('){
                if(appearance > 0){
                    ans += x;
                }
                appearance++;
            }
            else{
                appearance--;
                if(appearance > 0){
                    ans += x;
                }
            }
        }
        return ans;
    }
};