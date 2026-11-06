class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 0;

        for (int pile : piles) {
            minSpeed = max(minSpeed, pile);
        }

        int left = 1;
        int right = minSpeed;
        int middle = left + ((right - left) / 2);

        while (left < right) {
            long long time = checkSpeed(piles, middle);

            if (time <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }

            middle = left + ((right - left) / 2);
        }

        return left;
    }

    long long checkSpeed(vector<int>& piles, int k) {
        long long hours = 0;

        for (int pile : piles) {
            int curHours = (pile + k - 1) / k;
            hours += curHours;
        }

        return hours;
    }
};