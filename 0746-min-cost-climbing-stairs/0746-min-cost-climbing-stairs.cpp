class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // dp[i] = minimum cost required
        // to reach step i.
        vector<int> dp(n + 1, 0);

        // We can start from step 0 or step 1,
        // so their cost is 0.
        dp[0] = 0;
        dp[1] = 0;

        // Calculate minimum cost for every step.
        for (int i = 2; i <= n; i++) {

            // Option 1:
            // Come from previous step.
            int oneStep = dp[i - 1] + cost[i - 1];

            // Option 2:
            // Jump two steps.
            int twoStep = dp[i - 2] + cost[i - 2];

            // Take the cheaper option.
            dp[i] = min(oneStep, twoStep);
        }

        // dp[n] = minimum cost to reach the top.
        return dp[n];
    }
};