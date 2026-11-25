class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> valid;
        for (int i = 1; i < 10; i++) {
            valid[(char)(i + '0')] = 1;
        }
        
        // Try array implementation next!!!!!!
        // Create hashmap from 1 to 9 and store 9 in each value
        
        // Check every row and and subtract from value upon every
        // find... The finished result should be values of zero.
        for (const vector<char>& row : board) {
            
            unordered_map<char, int> rCheck = valid; //deep cpy
            for (const char& ch: row) {
                if (ch == '.') {continue;}
                if (!rCheck[ch]) {return false;}
                rCheck[ch]--;
            }
            // should have a uniformly decremented hashmap
        }


        for (int j = 0; j < 9; j++) {
            unordered_map<char, int> cCheck = valid; //deep cpy
            for (int i = 0; i < 9; i++) {
                char ch = board[i][j];
                if (ch == '.') {continue;}
                if (!cCheck[ch]) {return false;}
                cCheck[ch]--;
            }
        }

        for (int u = 0; u < 3; u++) {
            for (int v = 0; v < 3; v++) {
                
                unordered_map<char, int> kCheck = valid; // deep copy
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y <3; y++) {
                        // Kernel constructed
                        char ch = board[x + 3*u][y + 3*v];
                        if (ch == '.') {continue;}
                        if (!kCheck[ch]) {return false;}
                        kCheck[ch]--;
                    }
                }
            }
        }

        return true;

        //  Check for any duplicates within kernel of 3 by 3

        // check each row
        // check each column
        
    }
};
