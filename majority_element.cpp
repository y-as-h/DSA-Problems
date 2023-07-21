class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //// Moore's Voting Algorithm ////

        int majority;
        int count = 0;

        for(int i = 0; i < nums.size(); ++i){       // to find out the more frequent element in the array
            if(count == 0){
                count++;
                majority = nums[i];
            }
            else if(majority == nums[i]){
                count++;
            }
            else
                count--;
        }

        int cnt = 0;                                // to check if majority element occur more than n/2
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == majority)
                cnt++;
        }


        return majority;
    }
};
