class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int profit = INT_MIN;

        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                profit = max(profit, prices[right] - prices[left]);
            }

            right++;
        }

        return max(0, profit);
    }
};
