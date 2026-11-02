class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];

            if (numMap.count(compliment)) {
                return vector<int>{numMap[compliment], i};
            }

            numMap[nums[i]] = i;
        }

        return vector<int>{};
    }
};
