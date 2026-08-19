class Solution {
public:

int solve(string text1, string text2,int ind1,int ind2){
     
    //shifting of an index;
    vector<int>dp(ind2+1,0);
    if(ind1==0||ind2==0) return 0;

    for(int i=1;i<=ind1;i++){
        int diagonal = 0;

        for(int j=1;j<=ind2;j++){

            int temp = dp[j];

            if(text1[i-1]==text2[j-1]){
                dp[j]=1+diagonal;
            }
            else{
                dp[j]=max(dp[j],dp[j-1]);
            }

            diagonal = temp;
        }
    }

    return dp[ind2];
    
}

int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size();
    int m=text2.size();

    return solve(text1,text2,n,m);
}
};