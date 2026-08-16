class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case
        if (n == 1)
            return nums[0];

        // DP array
        vector<int> dp(n, 0);

        // Base cases
        // heving two size of arrays;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Build DP table
        for (int i = 2; i < n; i++) {

            int incl = dp[i - 2] + nums[i];
            int excl = dp[i - 1];

            dp[i] = max(incl, excl);
        }

        return dp[n - 1];
    }
}; 