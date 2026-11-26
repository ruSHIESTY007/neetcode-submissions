class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> bucket;
        if (strs.size() == 0) { return result; }
        if (strs.size() == 1) {
            return {{strs}};
        }

        // create a hashmap that holds the index of the strings which fit the anagram
        // the key to this hashmap would ig just be sorted ASCII values as an array?
        // First create a key for each word by making a 26 long array for freq table
        // convert this table into string and use it to hash the index/ word into bucket
        // via pushback
        for (int i = 0; i < strs.size(); i++) {
            int key[26] = {};
            string hash;
            for (char ch : strs[i]) {
                key[static_cast<int>(ch) - 'a']++;
            }
            
            // We want to turn the array into a key to use to index into 
            for (int x : key) {
                hash+= to_string(x) + "#";
            }

            // Use the new key
            bucket[hash].push_back(strs[i]);
        }

        // We have filled up all the buckets now create the solution
        int j = 0;
        for (const auto& key : bucket) {
            result.push_back(key.second);
        }

        // Now iterate through keys and pushback.
        return result;
    }
};

