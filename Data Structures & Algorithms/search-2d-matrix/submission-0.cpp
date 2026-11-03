class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        int middle = left + ((right - left) / 2);
        int foundIn = -1;

        while (left <= right) {
            middle = left + ((right - left) / 2);

            if (matrix[middle][0] <= target && matrix[middle].back() >= target) {
                foundIn = middle;
                break;
            }

            if (matrix[middle][0] > target) {
                right = middle - 1;
            } else if (matrix[middle].back() < target) {
                left = middle + 1;
            }
        }

        if (foundIn == -1) return false;

        left = 0;
        right = matrix[foundIn].size() - 1;
        middle = left + ((right - left) / 2);

        while (left <= right) {
            middle = left + ((right - left) / 2);

            if (matrix[foundIn][middle] == target) return true;

            if (matrix[foundIn][middle] > target) {
                right = middle - 1;
            } else if (matrix[foundIn][middle] < target) {
                left = middle + 1;
            }
        }

        return false;
    }
};
