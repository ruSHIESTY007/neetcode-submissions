class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {return false;}
        int check[26] = {};
        for (char ch : s1) {
            check[static_cast<int>(ch) - 'a']++;
        }

        int i = 0;
        int j = s1.size();
        int comp[26] = {};
        for (int k = 0; k < j; k++) {
            comp[static_cast<int>(s2[k]) - 'a']++;
        }
        
        while (j < s2.size()) {
            // compare
            if (equal(check, check + 26, comp)) { return true; }
            comp[static_cast<int>(s2[j++]) - 'a']++;
            comp[static_cast<int>(s2[i++]) - 'a']--;
        }
        if (equal(check, check + 26, comp)) { return true; } else { return false; }
        
    }
};
