class Solution {
public:
 int solve(int m, int n) {
     vector<int>dp(n,0);
    // base case;
        // if(m==0 && n==0) return 1;
        dp[0]=1;


        // Already calculated
        // if(dp[m][n] != -1)
        //     return dp[m][n];


        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){       
             int down=0;
             int right=0;
                    // From above
                    down = dp[j];
                    // From left
                    right = dp[j-1];
            
             dp[j]= down+right;
                
            }
            
        }      
        
        return dp[n-1];
    }


    int uniquePaths(int m, int n) {
       
        return solve(m,n);
    }
};
