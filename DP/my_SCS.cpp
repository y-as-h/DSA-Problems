class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string LCS = "";
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        for(int i = 0 ;i <= n; ++i){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= m; ++j){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = n;
        int j = m;

        while(i != 0 && j != 0){
            if(str1[i-1] == str2[j-1]){
                LCS.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }

        reverse(LCS.begin(), LCS.end());

        j = 0;
        int k = 0;
        string remains = str1;
        
        for(int i = 0; i < n; ++i){
            if(str1[i] == LCS[j]){
                k = i;
                break;
            }
        }

        for(int i = 0; i < m; ++i){
            if(j < LCS.size()){
                char alpha = str2[i];
                if(str2[i] != LCS[j]){
                    remains.insert(k, 1, alpha);
                    k++;
                }
                else{
                    j++;
                    k++;
                    for(int l = k; l < remains.size(); ++l){
                        if(j >= LCS.size()){
                            k = remains.size();
                            break;
                        }
                        if(j < LCS.size() && remains[l] == LCS[j]){
                            k = l;
                            break;
                        }
                    }
                }
            }
            else{
                remains.insert(k, 1, str2[i]);
                k++;
            }
        }



        return remains;
    }
};
