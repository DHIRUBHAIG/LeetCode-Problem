class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int m,int n){
     vector<int>dp(n,-1);
    if(obstacleGrid[0][0]==1) return 0; 
    dp[0]=1;
    // if(dp[m][n]!=-1) return dp[m][n];

    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1){
                dp[j] = 0;
                continue;
            }

            if(i==0 && j==0){
                dp[0]=1;
                continue;
            }
            int down=0;
             int right=0;
   

    if(i>0){
        //only down;
        right=dp[j];
    }
     if(j>0){
        // only right;
        down=dp[j-1];
        
    }
    
    dp[j]= right+down;

        }
    }
    
    return dp[n-1];
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solve(obstacleGrid,m,n);
    }
};