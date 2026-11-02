class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> numMap;
        vector<vector<int>> ret;

        for (int num : nums) {
            numMap[num]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]]--;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                numMap[nums[j]]--;

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int compliment = 0 - (nums[i] + nums[j]);

                if (numMap[compliment] > 0) {
                    ret.push_back({nums[i], nums[j], compliment});
                }
            }

            for (int j = i + 1; j < nums.size(); j++) {
                numMap[nums[j]]++;
            }
        }

        return ret;
    }
};
