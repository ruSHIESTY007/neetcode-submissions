class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;

        // -1 if there is no zero otherwise holds index of zero
        int zero = -1;
        vector<int> solution(nums.size());
        // manage condition where there is one zero and two zeros

        // thinking i should just keep a running product 
        // loop again through array and divide the elment
        for (int j = 0; j < nums.size(); j++) {
            int value = nums[j];

            // Case 1 where we find our first zero
            // Make it and continue so we can fix that particular index
            if (!value && zero < 0) {
                zero = j;
                continue;
            } else if (!value && zero >= 0) {
                // Case 2 where we find second zero..
                // Entire array will be zeros so return solution
                return solution;
            }

            // Case 3 where nothing special happens just multi on
            product*= value;
        }

        if (zero >= 0) {
            // We haveone zero
            solution[zero] = product;
            return solution;
        }

        // Normal operation
        for (int i = 0; i < nums.size(); i++) {
            solution[i] = product / nums[i];
        }

        return solution;


    }
};
