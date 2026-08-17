class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>&dp){
    if(obstacleGrid[0][0]==1) return 0; 
    if(m==0 && n==0){
        return 1;
    }
    if(dp[m][n]!=-1) return dp[m][n];

    if(obstacleGrid[m][n]==1) return 0;
    int down=0;
    int right=0;
   

    if(m==0){
        //only right;
        right=solve(obstacleGrid,m,n-1,dp);
    }
    else if(n==0){
        // only down;
        down=solve(obstacleGrid,m-1,n,dp);
        
    }
    else{
        // both right and down;
        right=solve(obstacleGrid,m,n-1,dp);
        down=solve(obstacleGrid,m-1,n,dp);
    }
    dp[m][n]= right+down;
    return dp[m][n];
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solve(obstacleGrid,m-1,n-1,dp);
    }
};