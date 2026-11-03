class Solution {
public:
    bool isValid(string s) {
        vector<char> stck;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stck.push_back(s[i]);
            } else {
                if (stck.empty()) return false;

                if ((s[i] == ')' && stck.back() != '(')
                    || (s[i] == '}' && stck.back() != '{')
                    || (s[i] == ']' && stck.back() != '[')
                ) {
                    return false;
                }

                stck.pop_back();
            }
        }

        if (!stck.empty()) return false;

        return true;
    }
};
