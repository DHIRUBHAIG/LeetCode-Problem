class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
            if(nums[i]>maxi){
                maxi=nums[i];
            }

        }
        int miniindex=-1;
        int maxiindex=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini){
                miniindex=i;
            }
            if(nums[i]==maxi){
                maxiindex=i;
            }
        }
        int leftmini=miniindex+1;
        int leftmaxi=maxiindex+1;

        int rightmini=nums.size()-miniindex;
        int rightmaxi=nums.size()-maxiindex;

        int left=min(leftmini,rightmini);
        int right=min(leftmaxi,rightmaxi);

        int l1=max(leftmini,leftmaxi);
        int r2=max(rightmini,rightmaxi);
        int minimum=min(l1,r2);
        int maxium=left+right;

        return min(minimum,maxium);

    
    }
};