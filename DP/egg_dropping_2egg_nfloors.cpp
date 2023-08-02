class Solution {
private:
    int solve(int n, int e, vector<vector<int>>& dp){
        if(e == 1)  return n;
        if(n == 0 || n == 1)    return n;
        if(dp[n][e] != -1)  return dp[n][e];

        int mini = 1e9;
        for(int k = 1; k <= n; ++k){
            int brek = solve(k-1, e-1, dp);
            int notbrek = solve(n-k, e, dp);
            mini = min(mini, 1+max(brek,notbrek));
        }

        return dp[n][e] = mini;
    }
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(n, 2, dp);
    }
};
