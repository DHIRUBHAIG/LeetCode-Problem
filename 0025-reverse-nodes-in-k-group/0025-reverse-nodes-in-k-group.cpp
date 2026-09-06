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
ListNode* reverse(ListNode* temp){
    ListNode* prev=NULL;
    while(temp!=NULL){
       ListNode* next=temp->next;
       temp->next=prev;
       prev=temp;
       temp=next; 
    }
    return prev;
}
ListNode* findkthnode(ListNode* temp,int k){
    k--;
    while(k--){
        if(temp!=NULL){
            temp=temp->next;
        }
        else{
            return NULL;
        }
        
    }
    return temp;
     
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
         
        ListNode* prevnode=NULL;
        while(temp!=NULL){
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==NULL){
                if(prevnode!=NULL){
                    prevnode->next=temp;
                    break;
                }
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            if(temp==head){
              head=kthnode;

            }
            else{
                prevnode->next=kthnode;
                
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    
    }
};