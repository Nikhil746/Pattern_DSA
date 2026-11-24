class Solution {
public:
    long long findNum(long long n, long long m, long long mid) {
        int row = n, col = 1;
        int count = 0;
        while (row >= 1 && col <= m) {
            long long val = row * col;
            if (val <= mid) {
                count = count + row ;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        // vector<vector<int>> matrix;
        // matrix = formMatrix(m,n);
        
        long long low = 1, high = (m*n);
        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ans = findNum(m, n, mid);
            if (ans < k) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};