class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-1; i > 0; --i){       // first loop to find the dip i.e. first value that is smaller the its next val
            if(nums[i-1] < nums[i]){
                int k = i;
                for(int j = i; j < n; ++j){ // second loop to find the smallest value that is greater than the dip val
                    if(nums[i-1] < nums[j]){
                        k = j;
                    }
                }                           
                int temp = nums[k];         // swaping them
                nums[k] = nums[i-1];
                nums[i-1] = temp;
                sort(nums.begin()+i, nums.end());   //sorting the vector from the dip+1 to end
                break;
            }
            // if the vector contains the largest possible permutation i.e.from end to start it is increasing without a dip
            if(i == 1){
                sort(nums.begin(), nums.end());
                break;
            }
        }
    }
};
