class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for(int i = 0; i <= n; ++i){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(j >= i)
                    dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
                
            }
        }
        
        return dp[n][n];
    }
};
