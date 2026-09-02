class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //vector<int>ans;
        for(int i=0;i<nums1.size();i++){
        
                if(nums1[i]%2!=0){
                //ans.push_back(nums1[i]);
                continue;
            }
            else{
                for(int j=0;j<nums1.size();j++){
                    if(i!=j){
                        if((nums1[i]-nums1[j]%2)!=0){
                           // ans.push_back(nums1[i]-nums1[j]);
                           continue;
                            break;
                        }
                        return false;
                    }
                }
                
            }
        
        }
        return true;
    }
};