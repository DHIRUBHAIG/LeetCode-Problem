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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr=head->next;
        // int mini1=head->val;
        // int maxi1=head->val;
        ListNode* prev=head;
        vector<int>ans;
        int count=1;


        while(curr->next!=NULL){
            count++;
            //local minima
            if(curr->val<prev->val && curr->next->val>curr->val){
                ans.push_back(count);

            }
            else if(curr->val>prev->val && curr->next->val<curr->val){
                ans.push_back(count);
            }
            // mini1=min(mini1,curr->val);
            // maxi1=max(maxi1,curr->val);
            prev=prev->next;
            curr=curr->next;

        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=1;i<ans.size();i++){
            
            mini=min(ans[i]-ans[i-1],mini);

            maxi=max(maxi,ans[i]-ans[0]);

        }
        vector<int>nums;
        if(mini!=INT_MAX){
            nums.push_back(mini);

        }
        if(maxi!=INT_MIN){
            nums.push_back(maxi);

        }
        
        
        return nums.empty()?vector<int>{-1,-1}:nums;
        
    }
};