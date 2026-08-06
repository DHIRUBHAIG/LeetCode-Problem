class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(),bills.end());
        int $5=0;
        int $10=0;
        int $20=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) $5++;
            else if(bills[i]==10){
                $10++;
                if($5>0) $5--;
                else return false;
            }
            else{
                $20++;
                if($5>0 && $10>0){
                    $5--;
                    $10--;
                }
                else if($5>2){
                    $5-=3;
                }
                else return false;

            }
        }
        return true;
    }
};