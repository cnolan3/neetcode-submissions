class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = left + (right - left) / 2;

        while (nums[middle] != target && left < right - 1) {
            if (target < nums[middle]) {
                right = middle;
            } else {
                left = middle;
            }

            middle = left + (right - left) / 2;
        }

        if (nums[middle] == target) return middle;
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;

        return -1;
    }
};
