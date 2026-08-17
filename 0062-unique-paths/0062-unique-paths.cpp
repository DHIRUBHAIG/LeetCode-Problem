class Solution {
public:
    int solve(int m, int n) {

        vector<int> dp(n, -1);

        // Base case
        dp[0] = 1;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0)
                    continue;

                int down = 0;
                int right = 0;

                if(i > 0) {
                    // From above
                    down = dp[j];
                }

                if(j > 0) {
                    // From left
                    right = dp[j - 1];
                }

                dp[j] = down + right;
            }
        }

        return dp[n - 1];
    }

    int uniquePaths(int m, int n) {
        return solve(m, n);
    }
};
