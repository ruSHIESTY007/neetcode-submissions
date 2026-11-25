class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Sort the array ig
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;

        // // Hard code ik ik its bad


        // Iterate strong pointer
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i-1] == nums[i]) {continue;}
            int l = i + 1;
            int r = nums.size() - 1;
            int strong = nums[i];

            // Loop to check for solutions
            while (l < r) {
  
                if (!(strong + nums[l] + nums[r])) {
                    // We found a match!!
                    vector<int> add = {strong, nums[l], nums[r]};
                    if (solution.size() == 0) {
                        solution.push_back(add);
                    } else if (solution[solution.size() - 1] != add) {
                        solution.push_back(add);
                    }
                    l++;
                    r--;
                    if (nums[l] == nums[l-1]) {l++; continue;} // idk if i need this
                    if (nums[r] == nums[r+1]) {r--; continue;} // or this
                } else if (strong + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return solution;
        
    }
};
