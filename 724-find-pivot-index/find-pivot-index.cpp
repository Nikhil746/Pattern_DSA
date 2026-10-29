class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        for (int i = 0; i < n; i++) {
            int right = sum - left - nums[i];
            if (left == right)
                return i;
            left += nums[i];
        }

        return -1;
    }
};