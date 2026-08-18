class Solution {
public:
int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>>&dp){
    if(m==0 && n==0) return grid[0][0];
    if(dp[m][n]!=-1) return dp[m][n];
    int right=INT_MAX;
    int down=INT_MAX;

    if(m==0) {
        right=grid[m][n]+solve(grid,m,n-1,dp);

    }
    else if(n==0){
        down=grid[m][n]+solve(grid,m-1,n,dp);
    }
    else{
        right=grid[m][n]+solve(grid,m,n-1,dp);
        down=grid[m][n]+solve(grid,m-1,n,dp);
    }
    

    dp[m][n]= min(right,down);
    return dp[m][n];
}
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(grid,m-1,n-1,dp); 
    }
};