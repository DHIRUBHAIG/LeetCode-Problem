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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode * temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        // If we have to delete the head
        if(count == n) {
            ListNode* delnode = head;
            head = head->next;
            delete delnode;
            return head;
        }

        int req=count-n-1;
        temp=head;
        for(int i=0;i<req;i++){
            temp=temp->next;
        }
        ListNode * delnode=temp->next;
        
        temp->next=temp->next->next;
        delete delnode;
        return head;
    }
};