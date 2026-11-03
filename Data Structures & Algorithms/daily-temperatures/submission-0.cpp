class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> stck;
        vector<int> ret(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            if (!stck.empty()) {
                while (!stck.empty() && temperatures[i] > stck.back().first) {
                    pair<int, int> tmp = stck.back();
                    stck.pop_back();

                    ret[tmp.second] = i - tmp.second;
                }
            }

            stck.push_back({temperatures[i], i});
        }

        return ret;
    }
};
