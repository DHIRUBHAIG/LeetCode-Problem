class Solution {
public:
    int numberOfSubstrings(string s) {

        int len = 0;
        int count = 0;

        unordered_map<char, int> mpp;

        int low = 0;

        for (int high = 0; high < s.size(); high++) {

            // If character is appearing for the first time
            if (mpp[s[high]] == 0) {
                count++;
            }

            // Add current character
            mpp[s[high]]++;

            // We have a, b and c
            while (count == 3) {

                // Current window is valid
                // All substrings from low to high
                // are valid after extending to the right
                len += s.size() - high;

                // Remove left character
                mpp[s[low]]--;

                // If character completely removed
                if (mpp[s[low]] == 0) {
                    count--;
                }

                low++;
            }
        }

        return len;
    }
};


