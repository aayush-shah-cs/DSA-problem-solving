class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //need to use the hash to check the frequency and add that letter into the ans string
        vector<string> res;
        string ans = "";

        if(s.length() < 10) return res;
        unordered_map<string, int> freq;

        for(int i=0;i<(int)s.length();i++){
            string sub = s.substr(i,10);
            freq[sub]++;

            if(freq[sub] == 2) res.push_back(sub);
        }
        return res;
    }
};