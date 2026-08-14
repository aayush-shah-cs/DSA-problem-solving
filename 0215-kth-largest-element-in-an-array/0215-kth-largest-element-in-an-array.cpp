class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto val : nums){
            pq.push(val);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
}; 

//1,2,2,3,3,4*,5,5,6 => k=4
// 1,2,3,4,5,6

//1,2,3,4,5*,6 => k=2