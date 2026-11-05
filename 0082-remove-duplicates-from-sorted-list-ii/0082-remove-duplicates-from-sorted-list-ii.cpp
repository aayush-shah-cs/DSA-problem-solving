
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        vector<int> arr;
        ListNode* temp = head;

        // Step 1: Store values
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Count frequencies
        unordered_map<int,int> mp;

        for(auto ele : arr) {
            mp[ele]++;
        }

        // Step 3: Store unique elements
        vector<int> arr2;

        for(auto ele : arr) {
            if(mp[ele] == 1) {
                arr2.push_back(ele);
            }
        }

        // Step 4: Construct new linked list
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for(auto x : arr2) {
            ListNode* newNode = new ListNode(x);

            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;
    }
};
