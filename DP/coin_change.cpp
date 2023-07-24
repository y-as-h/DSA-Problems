//minimum no of coins
class Solution {
private:
    long long recursion(vector<int>& coins, int amount, int n, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(n == 0)  return INT_MAX;
        if(dp[n][amount] != -1) return dp[n][amount];

        long long take = INT_MAX;
        if(amount >= coins[n-1])
            take = 1 + recursion(coins, amount-coins[n-1], n, dp);
        long long notake = recursion(coins, amount, n-1, dp);

        return dp[n][amount] = min(take, notake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        // long long ans = recursion(coins, amount, n, dp);

        // if(ans >= INT_MAX)
        //     return -1;
        
        // return (int)ans;

        for(int i = 0; i <= n; ++i){
            dp[i][0] = 0;
        }
        for(int j = 1; j <= amount; ++j){
            dp[0][j] = INT_MAX-1;
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= amount; ++j){
                if(j >= coins[i-1])
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        if(dp[n][amount] == INT_MAX-1)
            return -1;
        return dp[n][amount];
    }
}; 
