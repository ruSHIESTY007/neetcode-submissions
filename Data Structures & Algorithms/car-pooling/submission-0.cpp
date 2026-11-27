class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> val(1001);
        
        for (vector<int> t : trips) {
            for (int i = t[1]; i < t[2]; i++) {
                val[i]+=t[0];
                if (val[i] > capacity) { return false;}
            }
        }
        return true;
    }
};