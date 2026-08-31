class Solution {
public:
    string reversePrefix(string word, char ch) {
        int end=0;
        while(end < word.length()){
            if(ch == word[end]){
                reverse(word.begin(),word.begin()+end+1);
                break;
            }
            end++;
        }
        return word;
    }
};