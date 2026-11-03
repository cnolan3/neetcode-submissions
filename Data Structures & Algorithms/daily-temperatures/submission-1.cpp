class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stck;
        vector<int> ret(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            if (!stck.empty()) {
                while (!stck.empty() && temperatures[i] > stck.top().first) {
                    pair<int, int> tmp = stck.top();
                    stck.pop();

                    ret[tmp.second] = i - tmp.second;
                }
            }

            stck.push({temperatures[i], i});
        }

        return ret;
    }
};
