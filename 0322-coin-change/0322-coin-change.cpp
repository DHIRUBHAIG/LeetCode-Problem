class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp) {

        // Amount 0 requires 0 coins.
        if (amount == 0) {
            return 0;
        }

        // Negative amount is impossible.
        if (amount < 0) {
            return INT_MAX;
        }

        // If already calculated,
        // return the stored answer.
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int ans = INT_MAX;

        // Try every coin.
        for (int i = 0; i < coins.size(); i++) {

            // Find minimum coins for remaining amount.
            int result = solve(coins, amount - coins[i], dp);

            // If valid solution exists.
            if (result != INT_MAX) {
                ans = min(ans, 1 + result);
            }
        }

        // Store the answer.
        dp[amount] = ans;

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        // dp[i] = minimum coins required
        // to make amount i.
        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};