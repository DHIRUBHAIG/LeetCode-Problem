class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        // dp[i] = minimum number of coins
        // required to make amount i.
        //
        // amount + 1 means "impossible" initially.
        vector<int> dp(amount + 1, amount + 1);

        // 0 coins are needed to make amount 0.
        dp[0] = 0;

        // Calculate answer for every amount.
        for (int i = 1; i <= amount; i++) {

            // Try every coin.
            for (int j = 0; j < coins.size(); j++) {

                // We can use this coin only if
                // coin value is <= current amount.
                if (coins[j] <= i) {

                    // Use this coin:
                    //
                    // 1 = current coin
                    // dp[i - coins[j]] = coins needed
                    // for remaining amount.
                    dp[i] = min(
                        dp[i],
                        1 + dp[i - coins[j]]
                    );
                }
            }
        }

        // If dp[amount] is still amount + 1,
        // amount cannot be formed.
        if (dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];
    }
};