class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;

        for (int num : nums) {
            q.push(num);
        }

        int ret = 0;
        for (int i = 0; i < k; i++) {
            ret = q.top();
            q.pop();
        }

        return ret;
    }
};
