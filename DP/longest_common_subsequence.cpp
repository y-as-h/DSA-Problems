class Solution
{
    private:
    int recursion(int n, int m, string& s1, string& s2, vector<vector<int>>& dp){
        if(n == 0 || m == 0)    return 0;
        if(dp[n][m] != -1)  return dp[n][m];
        
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + recursion(n-1, m-1, s1, s2, dp);
        else
            return dp[n][m] = max(recursion(n-1, m, s1, s2, dp), recursion(n, m-1, s1, s2, dp));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recursion(n, m, s1, s2, dp);
    }
};
