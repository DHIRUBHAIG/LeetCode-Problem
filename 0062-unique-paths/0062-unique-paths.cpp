class Solution {
public:
 int solve(int m, int n,vector<vector<int>>&dp) {
    // base case;
        if(m==0|| n==0) return 1;
        // Already calculated
        if(dp[m][n] != -1)
            return dp[m][n];

        int down=0;
        int right=0;
      
        // if(m==0){
        //     //only right
        //      right=solve(m,n-1,dp);
        // }
        // else if(n==0){
        //     //only down;
        //      down=solve(m-1,n,dp);
        //}
        //else{
            // both down,right;
             down=solve(m-1,n,dp);
             right=solve(m,n-1,dp);

        //}
        dp[m][n]= down+right;
        return dp[m][n];
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};