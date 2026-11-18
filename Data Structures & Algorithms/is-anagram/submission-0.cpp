class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.size();
        if (size != t.size()) {return false;}
        int slots[26] = {0};
        for (int i = 0; i < size; i++) {
            slots[(int)s[i] - 0x61]++;
            slots[(int)t[i] - 0x61]--;
        }
        
        for (int k = 0; k < 26; k++) {
            if (slots[k] != 0) {return false;}
        }
        return true;
    }
};
