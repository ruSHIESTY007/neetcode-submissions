class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> memory = {
            {1, 1},
            {2, 2}
        };

        if (n<3) { return n; }

        int i = 3;
        while (i <= n) {
            int value = memory[i-1] + memory[i-2];
            memory[i] = value;
            i++;
        }

        return memory[i - 1];
        
    }
};
