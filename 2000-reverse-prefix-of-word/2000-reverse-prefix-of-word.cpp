class Solution {
public:
    string reversing(string& part,int end){
        int i = 0;
        while(i < end){
            char temp = part[i];
            part[i] = part[end];
            part[end] = temp;
            i++;
            end--;
        }
        return part;
    }
    string reversePrefix(string word, char ch) {
        for(int i=0;i<word.length();i++){
            if(ch == word[i]){
               return reversing(word,i);
            }
        }
        return word;
    }
};