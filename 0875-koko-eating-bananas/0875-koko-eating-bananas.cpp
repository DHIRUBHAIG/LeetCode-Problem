class Solution {
public:
bool ispossible(vector<int>&nums,int h,int mid){
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=(nums[i]+(mid-1))/mid;
    }
    if(sum<=h) return true;
    return false;
}
    int minEatingSpeed(vector<int>& nums, int h) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        long long  ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,h,mid)==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};