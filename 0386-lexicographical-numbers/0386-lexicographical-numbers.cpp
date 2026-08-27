class Solution { 
public: 
    vector<int> lexicalOrder(int n) { 

        vector<int> ans; 

        int curr = 1; 

        for (int i = 0; i < n; i++) { 

            ans.push_back(curr); 

            // Try to go deeper 
            if (curr * 10 <= n) { 
                curr *= 10; 
            } 

            // Cannot go deeper 
            else { 

                // Move back while last digit is 9
                while (curr % 10 == 9 || curr + 1 > n) { 
                    curr /= 10; 
                } 

                // Move to next number
                curr++; 
            } 
        } 

        return ans; 
    } 
};