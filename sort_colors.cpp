class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        // int blue = 0;
        int white = 0;

        int n = nums.size();

        for(int i = 0; i < n; ++i){
            if(nums[i] == 0)    red++;
            else if(nums[i] == 1)   white++;
            // else    blue++;
        }

        white += red;
        // blue += white;

        for(int i = 0; i < n; ++i){
            if(i < red) nums[i] = 0;
            else if(i < white)  nums[i] = 1;
            else    nums[i] = 2;
        }
    }
};
