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
        ListNode* prevA = list1;
        for(int i=0;i<a-1;i++){
            prevA = prevA->next;
        }
        ListNode* afterB = prevA;
        for(int i=0;i<b-a+2;i++){
            afterB = afterB->next;
        }

        ListNode* last = list2;
        while(last->next != nullptr){
            last = last->next;
        }
        prevA->next = list2;
        last->next = afterB;
        return list1;
    }
};