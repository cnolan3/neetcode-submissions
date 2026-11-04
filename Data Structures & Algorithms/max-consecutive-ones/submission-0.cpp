class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curCount = 0;
        int maxCount = 0;

        for (int num : nums) {
            if (num == 1) {
                curCount++;
            } else {
                curCount = 0;
            }

            maxCount = max(maxCount, curCount);
        }

        return maxCount;
    }
};