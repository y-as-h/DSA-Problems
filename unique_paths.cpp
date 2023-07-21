class Solution {
private:
    int recursion(int m, int n, vector<vector<int>>& dp){
        if(m < 0){
            return 0;
        }
        if(n < 0){
            return 0;
        }
        if(m == 0 && n == 0){
            return 1;
        }

        if(dp[m][n] != -1)  return dp[m][n];
        int down = recursion(m, n-1, dp);
        int right = recursion(m-1, n, dp);

        return dp[m][n] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recursion(m-1, n-1, dp);

        int N = m+n-2;
        int R = m-1;

        double ans = 1;

        for(int i = 1; i <= R; ++i){
            ans = ans*(N-R+i)/i;
        }

        return (int)ans;
    }
};
