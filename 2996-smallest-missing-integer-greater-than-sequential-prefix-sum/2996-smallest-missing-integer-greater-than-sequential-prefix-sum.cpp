class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int start=nums[0];
        int missing;
        for(int i=1;i<nums.size();i++){
             if((start+1)==nums[i]){
                start+=1;
             }
             else {
                missing=i;
                break;
             }
        }
        int sum=0;
        for(int j=0;j<missing;j++){
            sum+=nums[j];
        
        }
        
        while(true){
            bool flag=false;
             for(int i=0;i<nums.size();i++){
            if(sum==nums[i]){
                sum+=1;
                flag=true;
                break;
                

            }
        }
         // sum does not exist in nums
            if(flag == false)
                break;
        }

        
        
      return sum;  

    }
};