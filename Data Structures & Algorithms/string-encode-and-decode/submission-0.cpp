class Solution {
public:
    static constexpr char SOH = 0x01;
    static constexpr char STX = 0x02;
    static constexpr char ETX = 0x03;
    static constexpr char NUL = 0x00;


    // I was thinking of converting each character in the string into ascii hex and putting a character from ascii starting at STX and ETX character
    string encode(vector<string>& strs) {
        string send_message;
        const char* HEX = "0123456789ABCDEF";

        
        // Handle empty case
        if (strs.size() == 0) {
            return send_message;
        }

        for (const string& s : strs) {
            send_message += STX;

            for (int i = 0; i < s.size(); i++) {
                unsigned char ch = s[i];
                // Results in 8 bit number
                // index the first 4 into hex array
                send_message += HEX[ch >> 4]; // index high bits
                send_message += HEX[ch & 0x0F]; // Index low bits
                
                // my idea is to convert the char into the ascii
                // hex value then take that value 0x3F for eg
                // and save it in a string "3F" to append to msg
            }
            send_message += ETX;
        }

        return send_message;

    }

    vector<string> decode(string s) {
        vector<string> receive_message;

        // Handle empty case
        if (s.size()==0) {
            return receive_message;
        }
        
        int i = 0;
        int j = 0;
        string entry;
        while (i < s.size()) {
            if (s[i] == ETX) {
                // we reached the end of a string
                i++;
                j++;
                continue;
            }
            if (s[i] == STX) {
                i++;
                receive_message.push_back("");
                // begin normal string reading

            }
            if (s[i - 1] == STX && s[i] == ETX) {
                // if empty string then fix
                i++;
                receive_message[j++] = "";
                continue;
                // skip to next string
            }

            entry[0] = s[i++];
            entry[1] = s[i++];
            receive_message.back().push_back(static_cast<char>(stoi(entry, nullptr, 16)));
        }

        return receive_message;
    }
};
