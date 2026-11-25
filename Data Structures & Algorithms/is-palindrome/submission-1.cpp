class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            int l = static_cast<int>(s[i]);
            if (l > 64 && l < 91) {l+=0x20;}
            if (!((l > 47 && l < 58) || (l > 96 && l < 123))) {
                i++;
                continue;
            }
            
            int r = static_cast<int>(s[j]);
            if (r > 64 && r < 91) {r+=0x20;}
            if (!((r > 47 && r < 58) || (r > 96 && r < 123))) {
                j--;
                continue;
            }

            if (l != r) {return false;}
            i++;
            j--;
        }
        return true;
    }
};
