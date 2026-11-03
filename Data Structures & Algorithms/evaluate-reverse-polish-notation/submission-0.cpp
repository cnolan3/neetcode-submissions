class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stck;

        for (string token : tokens) {
            int num;

            if (parseInt(token, num)) {
                stck.push_back(num);
            } else {

                if (stck.size() < 2) return 0;

                int a = stck.back();
                stck.pop_back();
                int b = stck.back();
                stck.pop_back();

                if (token == "+") {
                    stck.push_back(a + b);
                } else if (token == "-") {
                    stck.push_back(b - a);
                } else if (token == "*") {
                    stck.push_back(a * b);
                } else if (token == "/") {
                    stck.push_back(b / a);
                }
            }
        }

        return stck.back();
    }

    bool parseInt(string& s, int& out) {
        auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), out);
        return ec == std::errc() && ptr == s.data() + s.size();
    }
};
