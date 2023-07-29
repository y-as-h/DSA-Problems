class Solution{
private:
    int recursion(int arr[], int i, int j, vector<vector<int>>& dp){
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        int tempAns = 1e9;
        for(int k = i; k < j; ++k){
            tempAns = min(tempAns, recursion(arr, i, k, dp) + recursion(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j]);
        }
        
        return dp[i][j] = tempAns;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return recursion(arr, 1, N-1, dp);
    }
};
