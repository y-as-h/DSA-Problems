class Solution
{
    private:
        int recursion(int W, int wt[], int val[], int n, vector<vector<int>>& dp){
           if(n == 0)    return 0;
           if(W == 0)    return 0;
           if(dp[n][W] != -1)   return dp[n][W];
       
           int take = 0;
           if(W >= wt[n-1])
            take = val[n-1] + recursion(W-wt[n-1], wt, val, n-1, dp);
            
           int notake = recursion(W, wt, val, n-1, dp);
           
           return dp[n][W] = max(take, notake);
        }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        // return recursion(W, wt, val, n, dp);
        
        for(int i = 0; i <= n; ++i){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= W; ++j){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= W; ++j){
                if(j >= wt[i-1]){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
    }
};
