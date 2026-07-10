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
    ListNode* swapPairs(ListNode* head) {
         if(head == NULL || head->next == NULL) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* point =dummy;
        
        
      
        while(point->next!=NULL && point->next->next!=NULL){
            //identify to swap
            ListNode* swap1= point->next;
            ListNode* swap2=point->next->next;
            //accutal swap;
            swap1->next=swap2->next;
            swap2->next=swap1;
            //prepare for next swap;
            point->next=swap2;
            point=swap1;

        }
         return dummy->next;
    }
};