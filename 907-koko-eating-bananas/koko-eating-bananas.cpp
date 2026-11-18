class Solution {
public:
    long totalHours(int k, int h, vector<int>& piles) {
        long totatlHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totatlHours = totatlHours + piles[i] / k;
            if (piles[i] % k != 0) {
                totatlHours++;
            }
        }
        return totatlHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int  maxTime = -1; 
        long low = 1, high = *max_element(piles.begin(), piles.end()); 

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long isFeed = totalHours(mid, h, piles);
            if (isFeed > h) {
                low = mid + 1;
            } else {
                maxTime = mid;
                high = mid - 1;
            }
        }
        return maxTime;
    }
};