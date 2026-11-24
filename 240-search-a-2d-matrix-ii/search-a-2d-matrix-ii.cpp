class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        if(n== 1 && m ==1){
            if(matrix[0][0] == target) return true;
            return false;
        }

        int row = n-1, col = 0;

        while(row >=0 && col <= m-1) {
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) {
                row --;
            } else {
                col++;
            }
        }
        return false;
    }
};