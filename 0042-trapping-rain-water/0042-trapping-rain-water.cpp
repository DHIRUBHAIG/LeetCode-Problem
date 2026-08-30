class Solution {
public:
    int trap(vector<int>& nums) {
       int leftmax=0;
       int rightmax=0;
       int left=0;
       int right=nums.size()-1;
       int water=0;
       while(left<=right){
        if(rightmax>=leftmax){
            if(leftmax<=nums[left] ){
                leftmax=nums[left];
                
            }
            else{
                water+=min(leftmax,rightmax)-nums[left];
                //water+=leftmax-nums[left];
            }

            left++;
        }
        else{
            if(rightmax<=nums[right]){
                rightmax=nums[right];
                
            }
            else{
                 water+=min(leftmax,rightmax)-nums[right];
               // water+=rightmax-nums[right];
            }
            right--;

        }
       }
       return water;
    }
};