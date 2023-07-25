class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        // string B = A;
        // reverse(B.begin(), B.end());
        
        for(int i = 0; i <= n; ++i){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(A[i-1] == A[n-j])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
        
        
    }
};
