class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() ==0) {
            return 0;
        }

        int test = 0;
        int min = 0;
        int end = 1;
        // Keep track of min with start;
        while (end < prices.size()) {
            int curr = prices[end] - prices[min];
            if (curr > test) {
                test = curr;
            } else if (curr<=0){
                // this means we found a new min
                min = end;
            }
            end++;
        }
        return test;
        
    }
};
