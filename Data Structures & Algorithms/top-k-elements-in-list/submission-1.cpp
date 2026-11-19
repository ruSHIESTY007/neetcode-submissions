class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        vector<int> solution;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            hashmap[nums[i]]++;
        }
        // We have a constructed hashamp with key as number and value as frequency
        // place each number into index of frequency

        vector<vector<int>> buckets(size + 1);
        
        for (auto& [value, freq] : hashmap) {
            buckets[freq].push_back(value);
        }
        int l = size + 1;
        int count = 0;
        while (l > 0 && count < k) {
            l--;
            vector<int> sample = buckets[l];
            if (sample.empty()) {
                continue;
            }
            solution.insert(solution.end(), sample.begin(), sample.end());
            count+= sample.size();
        }
        return solution;
    }
};
