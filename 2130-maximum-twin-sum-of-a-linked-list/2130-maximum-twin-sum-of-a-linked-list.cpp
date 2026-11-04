/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int left=0;
        int right = arr.size()-1;
        int ans = INT_MIN;
        while(left < right){
            ans = max(ans,arr[left]+arr[right]);
            left++;
            right--;
        } 
        return ans;
    }
};