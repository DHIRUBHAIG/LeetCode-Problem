class Solution {
public:
int solve(string &s1,string &s2,int n1,int n2,vector<vector<int>>&dp){
    if(n1<0||n2<0) return 0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(s1[n1]==s2[n2]){
      return  dp[n1][n2]=  1+solve(s1,s2,n1-1,n2-1,dp);
    }
     return dp[n1][n2]=  0 + max(solve(s1,s2,n1-1,n2,dp),solve(s1,s2,n1,n2-1,dp));
}
    int minDistance(string word1, string word2) {
        string s1=word1;
        string s2 = word2;
        
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
       int lcs=  solve(s1,s2,n1-1,n2-1,dp);
       return (n1-lcs)+(n2-lcs);
    }
};