class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int maxWater = 0;

        while (start < end) {
            int shorterWall = heights[start] < heights[end] ? heights[start] : heights[end];

            int water = (end - start) * shorterWall;

            maxWater = max(maxWater, water);

            if (heights[start] >= heights[end]) {
                end--;
            } else {
                start++;
            }
        }

        return maxWater;
    }
};
