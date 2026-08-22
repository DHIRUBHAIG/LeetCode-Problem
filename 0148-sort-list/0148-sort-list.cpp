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
    ListNode* sortList(ListNode* head) {

        vector<int> arr;
        ListNode* temp = head;

        // Store values
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Sort
        sort(arr.begin(), arr.end());

        // Put sorted values back into linked list
        temp = head;

        for(int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

        return head;
    }
};