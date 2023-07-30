class Solution{
    int recursion(string str, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp){
        if(i > j)   return 0;
        if(i == j){
            if(isTrue)
                return str[i] == 'T';
            return str[i] == 'F';
        }
        int third;if(isTrue) third=1;else third=0;
        
        if(dp[i][j][third] != -1)  return dp[i][j][third];
        
        int lt, lf, rt, rf;
        int ans = 0;
        for(int k = i; k < j-1; k+=2){
            lt = recursion(str, i, k, true, dp);
            lf = recursion(str, i, k, false, dp);
            rt = recursion(str, k+2, j, true, dp);
            rf = recursion(str, k+2, j, false, dp);
            if(str[k+1] == '&'){
                if(isTrue)
                    ans += lt*rt;
                else
                    ans += lf*rf + lt*rf + lf*rt;
            }
            else if(str[k+1] == '|'){
                if(isTrue)
                    ans += lf*rt + lt*rf + lt*rt;
                else
                    ans += lf*rf;
            }
            else if(str[k+1] == '^'){
                if(isTrue)
                    ans += lf*rt + lt*rf;
                else
                    ans += lf*rf + lt*rt;
            }
        }
        
        return dp[i][j][third] = ans%1003;
    }
public:
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(S.length(), vector<vector<int>>(S.length(), vector<int>(2, -1)));
        return recursion(S, 0, S.length()-1, true, dp);
    }
};
