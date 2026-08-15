class Solution {
public:
int fibo(int n,vector<int>&dp){
    // base case;
    if(n<=1) return n;
    //check if exist in dp arrays ->then return
    if(dp[n]!=-1) return dp[n];
    // store in dp;

    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    // return dp arrays;
    return dp[n];
}
    int fib(int n) {
        vector<int>dp(n+1,-1);
       return fibo(n,dp);
    }
};