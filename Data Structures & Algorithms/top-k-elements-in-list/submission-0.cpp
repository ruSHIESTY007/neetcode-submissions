class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]]++;
        }
        // We have a constructed hashamp with key as number and value as frequency

        // Take every value in the hashmap and push the freq as int and 
        for (const auto& [key, value] : hashmap) {
            pq.push({value, key});
        }


        int j = 0;
        vector<int> solution(k);
        while (j < k) {
            vector<int> sample(2);
            sample = pq.top();
            pq.pop();
            solution[j] = sample[1];
            j++;
        }
        return solution;
    }
};
