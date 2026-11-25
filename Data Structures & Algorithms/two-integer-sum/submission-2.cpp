class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.contains(nums[i])) {
                return {table[nums[i]], i};
            }
            table[target - nums[i]] = i;
        }
        return {};
    }
};
