class Solution {
public:
    vector<vector<int>>threeSum(vector<int>& nums) {
        vector<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    j++;
                    k--;
                    st.push_back(temp);
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }

            }
        }
        //  vector<vector<int>>arr(st.begin(),st.end());
        //  return arr;
        return st;
    }
};