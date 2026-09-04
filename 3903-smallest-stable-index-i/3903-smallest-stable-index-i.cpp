class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int maxi=INT_MIN;
       for(int i=0;i<nums.size();i++){
         maxi=max(maxi,nums[i]);
        //cout<<maxi<<" ";
        int j=nums.size()-1;
        int mini=INT_MAX;
        while(i<=j){
            mini=min(mini,nums[j]);
            j--;
        }
        //cout<<mini<<" ";
        if((maxi-mini)<=k) return i;
       } 
       return -1;
    }
};