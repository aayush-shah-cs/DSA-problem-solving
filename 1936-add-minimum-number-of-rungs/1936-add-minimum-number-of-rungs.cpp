class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int count=0;
        int prev=0;
        for(int rung : rungs){
            int gap = rung-prev;
            if(gap > dist){
                // count++; X
                count += (gap-1)/dist;
            }
            prev = rung;
        }
        return count;
    }
};