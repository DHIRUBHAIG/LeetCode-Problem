class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            // We are on the increasing side
            if(nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }

            // We are on the decreasing side
            else {
                high = mid;
            }
        }

        return low;
    }
};