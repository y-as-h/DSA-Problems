class Solution{   
private:
    bool recursion(vector<int> arr, int sum, int n, vector<vector<int>>& dp){
        if(sum == 0)    return true;
        if(n == 0 && sum != 0)  return false;
        if(dp[n][sum] != -1)    return dp[n][sum];
        
        bool take = false;
        if(sum >= arr[n-1])
            take = recursion(arr, sum-arr[n-1], n-1, dp);
        
        bool notake = recursion(arr, sum, n-1, dp);
        
        return dp[n][sum] = take||notake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // return recursion(arr, sum, n, dp);
        
        //tabulation
        for(int i = 0; i <= n; ++i){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= sum; ++j){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= sum; ++j){
                if(j >= arr[i-1])
                    dp[i][j] = (dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};
