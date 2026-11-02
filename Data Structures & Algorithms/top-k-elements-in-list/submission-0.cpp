class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> numFreq;
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, cmp> heap;
        vector<int> ret;

        for (int num : nums) {
            numFreq[num]++;
        }

        for (const auto& [num, freq] : numFreq) {
            heap.push(std::pair<int, int>{num, freq});
        }

        for (int i = 0; i < k; i++) {
            ret.push_back(heap.top().first);
            heap.pop();
        }

        return ret;
    }

    struct cmp {
        bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) const {
            return a.second < b.second;
        }
    };
};
