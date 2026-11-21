class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int solution = 0;
        if (!nums.size()) {return 0;}
        unordered_map<int, int> hashmap;
        // create the hashmap
        for (int val : nums) {
            hashmap[val] = 1;
        }

        for (auto& entry : hashmap) {
            //if (!hashmap.count(x)) {continue;} // We deleted
            //saving x cuz I need to mess with it
            // not sure if I can use x directly
            int total = entry.second;
            int key = entry.first + 1;
            while (hashmap.count(key)) {
                // check if next exists
                int freq = hashmap[key];

                // Check if it is a header key..
                if (freq != 1) {
                    // If it isn't a header key then 
                    total+=freq;
                    hashmap.erase(key); // not sure if ts is need
                    break;
                    // we found the "end" so break and keep going
                }
                // if it does than add to total and delete
                total++;
                hashmap.erase(key);
                key++;
            }
            // We finished loop and counted how many elements
            // exist after. Now add to the current location
            
            entry.second=total;
            solution = total > solution ? total : solution;
            if (solution == nums.size()) {break;}
        }
        return solution;
        // Now iterate through hashmap and 
        // use each index value as a key and check if an n-1 key
        // exists. If it does exist then 
        
    }
};
