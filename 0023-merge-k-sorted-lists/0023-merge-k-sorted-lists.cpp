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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    
    ListNode* EachIndex(vector<ListNode*>& lists,int i,int j){
        if(i == j) return lists[i];

        int mid = i + (j - i) / 2;

        ListNode* l1 = EachIndex(lists,i,mid);
        ListNode* l2 = EachIndex(lists,mid+1,j);

        return mergeTwoLists(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return EachIndex(lists,0,lists.size()-1);
    }
};