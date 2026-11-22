class Solution {
public:
    bool isBloomed(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, bouquets = 0;
        for (int x : bloomDay) {
            if (x <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        long long n = bloomDay.size();
        if ((long long)m * k > n)
            return -1;

        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            cout << mid << '\n';
            if (isBloomed(bloomDay, m, k, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};