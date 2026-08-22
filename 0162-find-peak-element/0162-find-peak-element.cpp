class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
       // if(n==1) return 0; // index of single element;
        int low=0; int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            // if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            //     return mid;
            // }
             if(nums[mid]>nums[mid+1]){
                high=mid;

            }
            else{
                 low=mid+1;
            }
        }
        return low;
    }
};