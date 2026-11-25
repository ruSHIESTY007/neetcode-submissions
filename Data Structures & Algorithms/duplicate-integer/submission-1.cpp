class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> check(nums.size());
        for (int x : nums) {
            if (check.contains(x)) {
                return true;
            } else {
                check.insert(x);
            }
        }
        return false;
    }
};