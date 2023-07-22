class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0; i < n; ++i){
	        sum += arr[i];
	    }
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
	    
	    for(int i = 0; i <= n; ++i){
	        dp[i][0] = 1;
	    }
	    for(int j = 1; j <= sum; ++j){
	        dp[0][j] = 0;
	    }
	    
	    for(int i = 1; i <= n; ++i){
	        for(int j = 1; j <= sum; ++j){
	            if(j >= arr[i-1])
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	   
	    int diff = sum;
	    
	    for(int j = 0; j <= sum/2; ++j){
	        if(dp[n][j])    diff = min(diff, sum-2*j);
	    }
	    
	    return diff;
	}
};
