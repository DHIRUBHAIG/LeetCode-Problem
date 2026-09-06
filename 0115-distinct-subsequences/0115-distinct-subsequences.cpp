
class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        // dp[j] = number of ways to form t[0...j-1]
        vector<unsigned long long> dp(m + 1, 0);

        // Empty t can always be formed in 1 way
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            // Go backwards so dp[j-1] belongs
            // to the previous row
            for (int j = m; j >= 1; j--) {

                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};


