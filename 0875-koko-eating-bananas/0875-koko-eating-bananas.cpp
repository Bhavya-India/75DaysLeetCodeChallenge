class Solution {
public:

    long long calculateHours(vector<int>& piles, int speed) {

        long long hours = 0;

        for (int bananas : piles) {

            hours += (bananas + speed - 1) / speed;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {

            int mid = left + (right - left) / 2;

            long long hours = calculateHours(piles, mid);

            if (hours <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};