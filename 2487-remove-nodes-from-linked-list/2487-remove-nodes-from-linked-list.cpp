class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        int maxi = INT_MIN;
        ListNode* prev = nullptr;
        while(curr) {
            if(curr->val < maxi) {
                prev->next = curr->next;
            }
            else {
                maxi = curr->val;
                prev = curr;
            }
            curr = curr->next;
        }
        return reverse(head);
    }
};