class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int>range(nums.size());
        int maxdigit=0;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            // *max_element(temp.begin(), temp.end())
            int mx=*max_element(temp.begin(), temp.end());
            int mn=*min_element(temp.begin(), temp.end());
             range[i]=mx-mn;
            maxdigit=max(maxdigit,range[i]);

        }
        int sum=0;
       for(int i=0;i<nums.size();i++){
        if(range[i]==maxdigit){
            sum+=nums[i];
        }
       }
        return sum;
    }
};