class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> resultant;

        for(auto word : operations){
            if(word == "C"){
                resultant.pop_back();
            }
            else if(word == "D"){
                resultant.push_back(2 * resultant.back());
            }
            else if(word == "+"){
                int n = resultant.size();
                resultant.push_back(resultant[n-1] + resultant[n-2]);            
            }
            else resultant.push_back(stoi(word));
        }
        int total = 0;
        for(auto val : resultant){
            total += val;
        }
        return total;
    }
};