class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            if(nums1[0]%2==0){
                if(nums1[i]%2==0){
                    ans.push_back(nums1[i]);

                }
                else{
                    for(int j=0;j<i;j++){
                        int rem=nums1[i]-nums1[j];
                        if(rem>=1 && rem%2==0){
                            ans.push_back(nums1[j]);
                            break;
                        }
                        else return false;
                    }
                }
               
            }
             else{
                    if(nums1[i]%2!=0){
                        ans.push_back(nums1[i]);
                    }
                    else{
                        for(int j=0;j<i;j++){
                            int rem=nums1[i]-nums1[j];
                            if(rem>=1 && rem%2!=0){
                                ans.push_back(nums1[j]);
                                break;
                            }
                            else return false;
                        }
                    }
                }
        }
        return true;
    }
};