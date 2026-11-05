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
        ListNode* new_ll = new ListNode(0);
        ListNode* tail = new_ll;
        int sum=0;
        ListNode* curr = head->next;
        while(curr){
            if(curr->val == 0){
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = newNode;
                sum = 0;
            }
            else{
                sum += curr->val;
            }
            curr = curr->next;
        }
        return new_ll->next;
    }
};