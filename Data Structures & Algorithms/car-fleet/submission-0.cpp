class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> l;

        for (int i = 0; i < position.size(); i++) {
            l.push_back({position[i], speed[i]});
        }

        sort(l.begin(), l.end());

        int numPacks = 0;
        double curTime = 0;
        for (int i = l.size() - 1; i >= 0; i--) {
            double time = (double)(target - l[i].first) / l[i].second;
            if (time > curTime) {
                numPacks++;
                curTime = time;
            }
        }

        return numPacks;

    }
};
