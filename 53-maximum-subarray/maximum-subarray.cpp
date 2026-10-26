class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubArraySum = nums[0], res = nums[0];
        int n = nums.size();

        for(int i=1;i<n;i++) {
            int val1 = nums[i];
            int val2 = maxSubArraySum + nums[i];

            maxSubArraySum = max(val1, val2);
            res = max(maxSubArraySum, res);
        }

        return res;
    }
};