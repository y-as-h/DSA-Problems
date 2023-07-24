class Solution{
private:
    int recursion(int n, int w, int val[], int wt[], vector<vector<int>>& dp){
        if(n == 0)  return 0;
        if(w == 0)  return 0;
        if(dp[n][w] != -1)  return dp[n][w];
        
        int take = 0;
        if(w >= wt[n-1])
            take = val[n-1] + recursion(n, w-wt[n-1], val, wt, dp);
        int notake = recursion(n-1, w, val, wt, dp);
        
        return dp[n][w] = max(take, notake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
        // return recursion(N, W, val, wt, dp);
        
        //tabulation
        for(int i = 0; i <= N; ++i){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= W; ++j){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= W; ++j){
                if(j >= wt[i-1])
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][W];
    }
};
