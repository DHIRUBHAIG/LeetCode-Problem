class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
        

         
         for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int l=i+1;l<nums.size();l++){
                if(l!=(i+1)  && nums[l]==nums[l-1]) continue;
            int j=l+1;
            int k=nums.size()-1;
            while(j<k){
                long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum>target) k--;
                else if(sum<target) j++;
                else{
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                   // sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }

            }
            }
         }
       return ans;
        
    }
};