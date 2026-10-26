class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), low = 0, count = 0, prod = 1;
        for (int high = 0; high < n; high++) {
            prod *= nums[high];
            while (prod >= k) {
                prod /= nums[low];
                low++;
            }
            count += high - low + 1;
        }
        return count;
    }
};