class Solution {
public:
    int climbStairs(int n) {
        vector<int> memory = {0, 1, 2};
        if (n<3) { return n; }

        int i = 3;
        while (i <= n) {
            int value = memory[i-1] + memory[i-2];
            memory.push_back(value);
            i++;
        }

        return memory.back();
        
    }
};
