class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> mpp;

        // Store frequency of characters in t
        for (char c : t)
            mpp[c]++;

        int required = t.size();      // Number of characters still needed
        int left = 0;                 // Left pointer of window
        int minLen = INT_MAX;         // Length of minimum window
        int startIndex = 0;           // Starting index of minimum window

        for (int right = 0; right < s.size(); right++) {

            // If current character is still required
            if (mpp[s[right]] > 0)
                required--;

            // Include current character in window
            mpp[s[right]]--;

            // Window contains all characters of t
            while (required == 0) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Remove left character from window
                mpp[s[left]]++;

                // If it becomes required again, window is invalid
                if (mpp[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
    }
};