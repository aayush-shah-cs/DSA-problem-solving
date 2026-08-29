class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = '\0';
        for(char chr : s){
            res = res ^ chr;
        }
        for(char chr : t){
            res = res ^ chr;
        }
        return res;
    }
};