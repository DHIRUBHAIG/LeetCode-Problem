class Solution {
public:

    int solve(int n, vector<int>& cost, vector<int>& dp) {

        // Base case:
        // Reaching the top costs nothing.
        if (n <= 1) {
            return 0;
        }

        // If already calculated,
        // return the stored answer.
        if (dp[n] != -1) {
            return dp[n];
        }

        // Come from n-1.
        int oneStep = solve(n - 1, cost, dp) + cost[n - 1];

        // Come from n-2.
        int twoStep = solve(n - 2, cost, dp) + cost[n - 2];

        // Store the minimum cost.
        dp[n] = min(oneStep, twoStep);

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // dp[i] = minimum cost required
        // to reach step i.
        vector<int> dp(n + 1, -1);

        return solve(n, cost, dp);
    }
};