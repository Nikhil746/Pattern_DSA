class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIndex = -1, n = matrix.size();
        int m = matrix[0].size();
        if(m == 1 && n == 1) {
            if(matrix[0][0] == target) return true;
            else return false;
        }
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(matrix[mid][0] <= target) {
                rowIndex = mid;
                low = mid + 1;
            } else  {
                high = mid - 1;
            }
        }
        cout << rowIndex << " " << '\n';
        if(rowIndex == -1) return false;
        low = 0, high = m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(matrix[rowIndex][mid] == target) return true;
            else if(matrix[rowIndex][mid] < target) low = mid + 1;
            else high = mid - 1; 
        }
        return false;
    }
};