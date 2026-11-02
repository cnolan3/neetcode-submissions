#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::ostringstream oss;

        for (string s : strs) {
            oss << std::to_string(s.size()) << "#" << s;
        }

        return oss.str();
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int start = 0;
        int end = 0;

        while(start < s.size()) {
            while (s[end] != '#') {
                end++;
            }

            string lenStr = s.substr(start, (end - start));
            int len = std::stoi(lenStr);

            string dataStr = s.substr(end + 1, len);

            ret.push_back(dataStr);

            end = end + len + 1;
            start = end;
        }

        return ret;
    }
};
