class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> numFreq;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> ret;

        for (int num : nums) {
            numFreq[num]++;
        }

        for (const auto& [num, freq] : numFreq) {
            buckets[freq].push_back(num);
        }

        for (int i = buckets.size() - 1; i >= 0; i--) {
            if (buckets[i].empty()) continue;

            for (int num : buckets[i]) {
                ret.push_back(num);
                k--;
            }

            if (k <= 0) break;
        }

        return ret;
    }
};
