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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head;
        ListNode* curr = head->next;
        int sum = 0;

        while(curr){
            if(curr->val == 0) {
                modify->val = sum;
                sum = 0;
                modify->next = curr->next;
                modify = modify->next;
            }
            else{
                sum += curr->val;
            }
            curr = curr->next;
        }
        return head;
    }
};