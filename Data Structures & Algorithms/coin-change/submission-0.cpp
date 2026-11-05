class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int coin : coins) {
            if (coin <= amount) {
                dp[coin] = 1;
            }
        }

        for (int i = 1; i < dp.size(); i++) {
            if (dp[i] == -1) {
                int smallest = INT_MAX;
                for (int coin : coins) {
                    if (coin <= i && dp[i - coin] != -1) {
                        int remaining = i - coin;
                        smallest = min(smallest, dp[remaining] + 1);
                    }
                }
                if (smallest != INT_MAX) dp[i] = smallest;
            }
        }

        return dp.back();
    }
};