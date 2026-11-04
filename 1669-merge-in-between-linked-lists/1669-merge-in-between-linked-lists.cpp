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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<ListNode*> temp_store;
        ListNode* temp = list1;
        while(temp != NULL){
            temp_store.push_back(temp);
            temp = temp->next;
        }
        ListNode* prevA = temp_store[a-1];
        ListNode* afterB = temp_store[b+1];

        ListNode* last = list2;
        while(last->next != NULL){
            last = last->next;
        }
        prevA->next = list2;
        last->next = afterB;
        return list1;
    }
};