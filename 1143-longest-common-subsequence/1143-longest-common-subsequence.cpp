class Solution {
public:
// int solve(string text1, string text2,int ind1,int ind2,vector<vector<int>>&dp){
//     if(ind1<0||ind2<0) return 0;
//     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//     if(text1[ind1]==text2[ind2]){
//         return dp[ind1][ind2]= 1+solve(text1,text2,ind1-1,ind2-1,dp);
//     }
//     return dp[ind1][ind2]= 0+ max(solve(text1,text2,ind1-1,ind2,dp),solve(text1,text2,ind1,ind2-1,dp));
// }

int solve(string text1, string text2,int ind1,int ind2){
     
    //shifting of an index;
    vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,-1));
    if(ind1==0||ind2==0) return 0;
    for(int i=1;i<=ind1;i++){
        for(int j=1;j<=ind2;j++){
            if(dp[0][0]==0) {
                dp[0][0]=0;
                continue;

            }

            // if(dp[i][j]!=-1) return dp[i][j];
    if(text1[i-1]==text2[j-1]){
         dp[i][j]= 1+ dp[i-1][j-1];
    }
    else{
        dp[i][j]= 0+ max(dp[i-1][j],dp[i][j-1]);
    }

        }
    }
   return  dp[ind1][ind2];
    
}
    int longestCommonSubsequence(string text1, string text2) {
       int n=text1.size();
       int m=text2.size();
       // vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(text1,text2,n+1,m+1);
    }
};