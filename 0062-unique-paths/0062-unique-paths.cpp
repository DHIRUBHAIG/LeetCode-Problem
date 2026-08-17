class Solution {
public:
 int solve(int m, int n) {
     vector<vector<int>>dp(m,vector<int>(n,-1));
    // base case;
        // if(m==0 && n==0) return 1;
        dp[0][0]=1;


        // Already calculated
        // if(dp[m][n] != -1)
        //     return dp[m][n];


        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0){
                    dp[0][0]=1;
                    continue;

                }
                    
             int down=0;
             int right=0;
             if(i > 0) {
                    // From above
                    down = dp[i-1][j];
                }

                if(j > 0) {
                    // From left
                    right = dp[i][j-1];
                }
             dp[i][j]= down+right;
                
            }
            
        }      
        
        return dp[m-1][n-1];
    }


    int uniquePaths(int m, int n) {
       
        return solve(m,n);
    }
};
