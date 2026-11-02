class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forwardProd(nums.size() + 2, 1);
        vector<int> backProd(nums.size() + 2, 1);
        vector<int> ret;

        int running = 1;
        for (int i = 0; i < nums.size(); i++) {
            running *= nums[i];
            forwardProd[i + 1] = running;
        }

        running = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            running *= nums[i];
            backProd[i + 1] = running;
        }

        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(forwardProd[i] * backProd[i + 2]);
        }

        return ret;
    }
};
