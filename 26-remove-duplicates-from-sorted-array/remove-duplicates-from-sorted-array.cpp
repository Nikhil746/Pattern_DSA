class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 1;
        if (n <= 1)
            return 1;
        while (i < n && j < n) {
            if (arr[j] == arr[j - 1]) {
                j++;
                continue;
            }
            i++;
            arr[i] = arr[j];
            j++;
        }
        return i + 1;
    }
};