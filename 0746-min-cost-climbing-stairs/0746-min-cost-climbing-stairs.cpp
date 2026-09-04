class Solution {
public:
    int solve(vector<int>& cost, int n) {
       
       int prev1=0;
        int prev2=0;
        for(int i=2;i<=cost.size();i++){
            int onestep= prev1 + cost[i-1];
            int twostep=prev2 + cost[i-2];
            int curr=min(onestep,twostep);
            prev2=prev1;
            prev1=curr;
    
        }       
        return prev1;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        return solve(cost, n);
    }
};