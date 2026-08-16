class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case
        if (n == 1)
            return nums[0];

        

        // Base cases
        // heving two size of arrays;
       int prev2 = nums[0];
       int prev1 = max(nums[0], nums[1]);

        // Build DP table
        for (int i = 2; i < n; i++) {

            int incl = prev2 + nums[i];
            int excl = prev1;

           int curr = max(incl, excl);
            prev2=prev1;
            prev1=curr;

        }

        return prev1;
    }
}; 