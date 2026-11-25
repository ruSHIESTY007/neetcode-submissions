class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false;}
        vector<int> slots(26);
        for (int i = 0; i < s.size(); i++) {
            slots[static_cast<int>(s[i]) - 'a']++;
        }
        for (int j = 0; j < t.size(); j++) {
            int index = static_cast<int>(t[j]) - 'a';
            if (!slots[index]) {
                return false;
            }
            slots[index]--;
        }
        return true;

    }
};
