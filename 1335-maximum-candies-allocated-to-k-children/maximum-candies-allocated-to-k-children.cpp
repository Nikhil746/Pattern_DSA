class Solution {
public:
    bool isDistributed(int guess, vector<int>& piles, int n, long long k) {
        long long count = 0;
        for(int i=0;i<n;i++) {
            count += (piles[i] / guess);
            if(count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int res = 0;

        int low = 1, high = *max_element(candies.begin(), candies.end());

        while (low <= high) {
            int guess = low + (high - low) / 2;
            if (isDistributed(guess, candies, n, k)) {
                res = guess;
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return res;
    }
};