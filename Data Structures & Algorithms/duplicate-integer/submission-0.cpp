class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> existance;
        for (int i = 0; i < nums.size(); i++) {
            if (existance[nums[i]]) {
                return true;
            }
            existance[nums[i]] = true;
        }
        return false;
    }
};