class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);
        int volume = 0;

        int highest = 0;
        for (int i = 0; i < height.size(); i++) {
            highest = max(highest, height[i]);
            prefix[i] = highest;
        }
        cout << endl;

        highest = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            highest = max(highest, height[i]);
            suffix[i] = highest;
        }

        for (int i = 0; i < height.size(); i++) {
            volume += max(0, min(prefix[i], suffix[i]) - height[i]);
        }

        return volume;
    }
};
