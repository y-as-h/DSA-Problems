class Solution {
private:
    int recursion(vector<int>& nums, int target, int n, vector<vector<int>>& dp){
        if(n == 0 && target != 0)   return 0;
        if(n == 0 && target == 0)   return 1;
        if(dp[n][target] != -1) return dp[n][target];

        int take = 0;
        if(target >= nums[n-1])
            take = recursion(nums, target-nums[n-1], n-1, dp);
        int notake = recursion(nums, target, n-1, dp);

        return dp[n][target] = take+notake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }

        if(target > sum)    return 0;
        if((sum+target)%2 == 1) return 0;
        if(sum+target < 0)  return 0;
        int targetNew = (sum+target)/2;     //target == diff

        vector<vector<int>> dp(n+1, vector<int>(targetNew+1, -1));

        return recursion(nums, targetNew, n, dp);
    }
};
