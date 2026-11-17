class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            if (check.count(target - value)) {
                return {check[target - value], i};
            }
            check[value] = i;
        }
        return {};
    }
};
