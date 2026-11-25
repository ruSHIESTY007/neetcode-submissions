class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> solution(2);

        while (i < j) {
            int l = numbers[i];
            int r = numbers[j];
            if (l+r == target){
                solution[0] = i + 1;
                solution[1] = j + 1;
                return solution;
            }
            if (l + r > target) {
                j--;
            } else {
                i++;
            }
        }       
        return solution;        
    }
};
