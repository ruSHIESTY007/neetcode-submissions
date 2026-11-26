class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) { return 0; }
        unordered_set<char> find;
        int l = 0, r = 0;
        int result = 1;

        while (r < s.size()) {

            // Say we found a match!
            if (find.count(s[r])) {
                while (find.count(s[r])) {
                    find.erase(s[l]);
                    l++;
                }
                find.insert(s[r]);
            } else {
                // we didn't find anything
                find.insert(s[r]);
                result = find.size() > result ? find.size() : result;
            }
            r++;
        }
        return result;
    }
};
