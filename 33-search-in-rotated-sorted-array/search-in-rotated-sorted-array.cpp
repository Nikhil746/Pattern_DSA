class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 0 || (n == 1 && arr[0] != target))
            return -1;
        if (n == 1 && arr[0] == target)
            return 0;
        int low = 0, high = n - 1;
        // int rotatedIndex = -1;
        // while(low <= high) {
        //     int mid = low + (high - low) / 2;
        //     if(arr[mid] <= arr[n-1]) {
        //         high = mid - 1;
        //         rotatedIndex = mid;
        //     } else {
        //         low = mid +1;
        //     }
        // }

        // low = rotatedIndex, high = n-1;

        // while(low <= high) {
        //     int mid = low + (high - low) / 2;
        //     if(arr[mid] == target) return mid;
        //     else if (arr[mid] < target) {
        //         low = mid + 1;
        //     } else {
        //         high = mid - 1;
        //     }
        // }

        // return -1;    MY LOGIC

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;

            if (arr[mid] > arr[n - 1]) {
                if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    if (arr[0] > target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                continue;
            }
            if (arr[mid] > target) {
                high = mid - 1;
            } else {
                if (arr[n - 1] < target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};