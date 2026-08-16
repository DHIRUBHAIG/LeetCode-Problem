class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // prev2 = dp[i-2]
        int prev2 = 0;

        // prev1 = dp[i-1]
        int prev1 = 0;

        for (int i = 2; i <= n; i++) {

            // Cost if we come from i-1.
            int oneStep = prev1 + cost[i - 1];

            // Cost if we come from i-2.
            int twoStep = prev2 + cost[i - 2];

            // Minimum cost to reach current step.
            int curr = min(oneStep, twoStep);

            // Move forward.
            prev2 = prev1;
            prev1 = curr;
        }

        // prev1 contains the minimum cost
        // to reach the top.
        return prev1;
    }
};