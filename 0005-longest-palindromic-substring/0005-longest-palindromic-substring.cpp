class Solution {
public:
    string longestPalindrome(string s) {
        string maxp = "";

        // Odd length palindrome
        for (int i = 0; i < s.size(); i++) {

            int low = i;
            int high = i;

            while (low >= 0 && high < s.size()) {

                if (s[low] == s[high]) {

                    string p = s.substr(low, high - low + 1);

                    if (p.size() > maxp.size()) {
                        maxp = p;
                    }

                    low--;
                    high++;
                }
                else {
                    break;
                }
            }
        }

        // Even length palindrome
        for (int i = 0; i < s.size() - 1; i++) {

            int low = i;
            int high = i + 1;

            while (low >= 0 && high < s.size()) {

                if (s[low] == s[high]) {

                    string p = s.substr(low, high - low + 1);

                    if (p.size() > maxp.size()) {
                        maxp = p;
                    }

                    low--;
                    high++;
                }
                else {
                    break;
                }
            }
        }

        return maxp;
    }
};