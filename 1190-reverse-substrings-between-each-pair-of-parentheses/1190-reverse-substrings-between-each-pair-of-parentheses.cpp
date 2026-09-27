class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        vector<int> stack;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else if (s[i] == ')') {
                int j = stack.back();
                stack.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string result = "";
        int direction = 1;
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        
        return result;
    }
};