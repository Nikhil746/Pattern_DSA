class Solution {
public:
    bool highCitation(vector<int>& citations, int n, int mid) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] >= mid)
                count++;
        }
        return count >= mid ? true : false;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 1, low = 0, high = citations[n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (highCitation(citations, n, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};