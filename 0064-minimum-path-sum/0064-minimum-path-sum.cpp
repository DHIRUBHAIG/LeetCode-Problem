class Solution {
public:
int solve(vector<vector<int>>& grid,int m,int n){
    // if(m==0 && n==0) return grid[0][0];
    // if(dp[m][n]!=-1) return dp[m][n];
    // int right=INT_MAX;
    // int down=INT_MAX;

    // if(m==0) {
    //     right=grid[m][n]+solve(grid,m,n-1);

    // }
    // else if(n==0){
    //     down=grid[m][n]+solve(grid,m-1,n);
    // }
    // else{
    //     right=grid[m][n]+solve(grid,m,n-1);
    //     down=grid[m][n]+solve(grid,m-1,n);
    // }
    

    // dp[m][n]= min(right,down);
    // return dp[m][n];

    vector<int>dp(n,-1);

    // Base case
    dp[0] = grid[0][0];
   
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(i == 0 && j == 0)
                    continue;
         int right=INT_MAX;
    int down=INT_MAX;
            if(i==0) {
        right=grid[i][j]+dp[j-1];

    }
    else if(j==0){
        down=grid[i][j]+dp[j];
    }
    else{
        right=grid[i][j]+dp[j-1];
        down=grid[i][j]+dp[j];
    }
    dp[j]= min(right,down);

        }
    }
    return dp[n-1];
}
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       //vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(grid,m,n); 
    }
};
