class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid = low + (high - low) / 2;

        // first occurence of value
        while (low <= high) {
            if (nums[mid] == target) {
                res[0] = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            mid = low + (high - low) / 2;
        }
        if (res[0] == -1)
            return res;

        // last occrence

        low = 0, high = n - 1;
        mid = low + (high - low) / 2;
        while (low <= high) {
            if (nums[mid] == target) {
                res[1] = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            mid = low + (high - low) / 2;
        }

        return res;
    }
};