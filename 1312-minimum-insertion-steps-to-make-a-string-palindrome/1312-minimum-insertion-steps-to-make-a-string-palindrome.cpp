class Solution {
public:
// n1-longest subsequence pallindromic==minium inseration step to make a string.
int solve(string &s1,string &s2,int n1,int n2,vector<vector<int>>&dp){
    if(n1<0||n2<0) return 0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(s1[n1]==s2[n2]){
        return dp[n1][n2] =1+solve(s1,s2,n1-1,n2-1,dp);
    }
    return dp[n1][n2]=  0+max(solve(s1,s2,n1-1,n2,dp),solve(s1,s2,n1,n2-1,dp));
}
    int minInsertions(string s) {
       int n1=s.size();
       string s1=s;
       string s2=s;
       reverse(s2.begin(),s2.end());
       vector<vector<int>>dp(n1,vector<int>(n1,-1));
       int lcs=solve(s1,s2,n1-1,n1-1,dp);
       return n1-lcs;

    }
};