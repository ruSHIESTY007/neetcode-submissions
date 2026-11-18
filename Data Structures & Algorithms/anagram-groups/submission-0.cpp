class Solution {
int ASCI_A = 0x61;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) { return {}; }
        vector<vector<string>> solution;
        if (strs.size() == 1) { return {strs}; }
        unordered_map<string, vector<string>> buckets;

        // Now that the extraordinary conditions have been taken care of...
        for (int i = 0; i < strs.size(); i++) {
            int word_key[26] = {0};
            for (int k = 0; k < strs[i].size(); k++) {
                word_key[(int)strs[i][k] - ASCI_A]++;
            }
            string string_key = "";
            for (int count : word_key) {
                string_key += to_string(count) + '#';
            }

            buckets[string_key].push_back(strs[i]);
        }

        // Now we have a completed hashmap with keys that have
        // arrays of strings
        solution.reserve(buckets.size());
        for (auto& [key, value] : buckets) {
            solution.push_back(value);
            // Add each array
        }
        return solution;
    }
};

