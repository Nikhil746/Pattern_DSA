class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0, high = 0, res = 0;
        int tempArr[2] = {0};
        int n = nums.size();
        while (high < n) {
            tempArr[nums[high]]++;
            while (tempArr[0] > k) {
                tempArr[nums[low]]--;
                low++;
            }
            int len = (high - low) + 1;
            res = max(len, res);
            high++;
        }

        return res;
    }
};