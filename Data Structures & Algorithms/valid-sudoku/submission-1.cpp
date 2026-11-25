class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Attemping bitwise mainuplaiton and checking
        // Create a mask for just the row and column first
        int rMask[9] = {}, cMask[9] = {}, sMask[9] = {};

        for (int i = 0; i < 9; i++ ) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];

                // if its empty just continue;
                if (ch == '.') {continue;}

                // Check if ch is contained in any of the masks
                int bit = 1 << (ch - '1');
                if ((rMask[i] & bit) ||
                    (cMask[j] & bit) ||
                    (sMask[3*(i/3) + (j/3)] & bit)) {return false;}

                // If not contained then add to all three by flipping the bit
                rMask[i] |= bit;
                cMask[j] |= bit;
                sMask[3*(i/3) + (j/3)] |= bit;
            }
        }
        return true;

    }
};
