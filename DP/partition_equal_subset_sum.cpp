class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; ++i)
            sum += arr[i];
            
        if(sum%2 == 1)
            return 0;
            
        sum = sum/2;
            
        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        
        for(int i = 0; i <= N; ++i){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= sum; ++j){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= sum; ++j){
                if(j >= arr[i-1])
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }
};
