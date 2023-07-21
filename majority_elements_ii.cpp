class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        ////    Boyer-Moore Majority Vote Algorithm
        int major1 = INT_MIN, major2 = INT_MIN;
        int count1 = 0, count2 = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i){
            if(count1 == 0 && nums[i] != major2){
                count1 = 1;
                major1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != major1){
                count2 = 1;
                major2 = nums[i];
            }
            else if(major1 == nums[i]){
                count1++;
            }
            else if(major2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }

        vector<int> ans;
        
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; ++i){
            if(nums[i] == major1)
                cnt1++;
            if(nums[i] == major2)
                cnt2++;
        }

        if(cnt1 > n/3)
            ans.push_back(major1);
        if(cnt2 > n/3)
            ans.push_back(major2);

        return ans;
    }
};
