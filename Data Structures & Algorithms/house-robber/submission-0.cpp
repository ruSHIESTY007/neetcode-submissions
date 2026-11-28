class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        if (nums.size() == 2) {return max(nums[0], nums[1]);}
        int best[100];
        best[0] = nums[0];
        best[1] = max(nums[0], nums[1]);
        
        int i = 2;

        while (i < nums.size()) {
            best[i] = max(best[i-1], best[i-2] + nums[i]);
            i++;
        }

        return best[--i];

        
    }
};
