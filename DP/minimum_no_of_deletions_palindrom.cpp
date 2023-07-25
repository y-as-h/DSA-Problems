int minDeletions(string str, int n) { 
    //complete the function here 
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    
    for(int i = 0; i <= n; ++i){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <=n; ++j){
            if(str[i-1] == str[n-j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return n-dp[n][n];
} 
