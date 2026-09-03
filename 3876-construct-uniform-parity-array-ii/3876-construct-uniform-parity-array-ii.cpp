class Solution {
public:
// | Operation       | Result |
// | --------------- | ------ |
// | **Even − Even** | Even   |
// | **Odd − Odd**   | Even   |
// | **Even − Odd**  | Odd    |
// | **Odd − Even**  | Odd    |

    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // Minimum is odd:
        //converatble in odd of all even
        // every even number can become odd by subtracting mn.
        if (mn % 2 != 0)
            return true;

        // Minimum is even:
        // every element must already be even.
        for (int x : nums1) {
            if (x % 2 != 0)
                return false;
        }

        return true;
    }
};