class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>nums;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }

        }
        while(i<n1){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            nums.push_back(nums2[j]);
            j++;
        }
        float ans;
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        if(n%2==0){
            //even;
             ans=((nums[mid]+nums[mid+1])/2.0);

        }
        else{
            //odd;
            ans=nums[mid];
        }
        return ans;

    }
};