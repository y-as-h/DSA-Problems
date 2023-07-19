class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int index = abs(nums[i]);
            if(nums[index] < 0){
                return index;
            }
            nums[index] = -nums[index];
        }
        return 0;
    }

    /* Another approach
    / We can use fast and slow pointers
    / traverse both pointers in the cycle until both meet
    / now put one pointer at the start of array
    / move one step from both fast and slow pointer
    / they meet at the duplicate number
    */
};
