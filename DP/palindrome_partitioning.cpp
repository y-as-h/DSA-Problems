class Solution{
private:
    bool isPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int recursion(string& str, int i, vector<int>& dp){
        if(i == str.size()) return 0;
        if(dp[i] != -1)   return dp[i];
        
        int tempAns = 1e9;
        for(int j = i; j < str.size(); ++j){
            if(isPalindrome(str, i, j)){
                tempAns = min(tempAns, 1 + recursion(str, j+1, dp));
            }
        }
        
        return dp[i] = tempAns;
    }
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int>dp(str.length()+1, -1);
        // return recursion(str, 0, dp)-1;
        
        dp[n] = 0;
        for(int i = n-1; i >=0; --i){
            int tempAns = 1e9;
            for(int j = n-1; j >= i; --j){
                if(isPalindrome(str, i, j))
                    tempAns = min(tempAns, 1 + dp[j+1]);
            }
            dp[i] = tempAns;
        }
        
        return dp[0]-1;
        
    }
};
