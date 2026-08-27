class Solution {
public:

    bool dfs(string &target, vector<int>& freq,
             int index, string &ans) {

        int n = target.size();

        // We matched the entire target.
        // Equal is NOT enough, so we need to backtrack
        // and make some previous position greater.
        if (index == n) {
            return false;
        }

        int t = target[index] - 'a';

        // ==================================================
        // STEP 1: Try to MATCH target[index]
        // ==================================================

        if (freq[t] > 0) {

            freq[t]--;
            ans.push_back(target[index]);

            if (dfs(target, freq, index + 1, ans)) {
                return true;
            }

            // BACKTRACK
            ans.pop_back();
            freq[t]++;
        }

        // ==================================================
        // STEP 2: Try to make current position GREATER
        // ==================================================

        for (int c = t + 1; c < 26; c++) {

            if (freq[c] == 0)
                continue;

            // Choose smallest possible greater character
            ans.push_back(char('a' + c));
            freq[c]--;

            // Once greater, minimize the rest.
            for (int x = 0; x < 26; x++) {

                while (freq[x] > 0) {

                    ans.push_back(char('a' + x));
                    freq[x]--;
                }
            }

            return true;
        }

        // No solution from this state
        return false;
    }


    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans;

        bool found = dfs(target, freq, 0, ans);

        if (found)
            return ans;

        return "";
    }
};