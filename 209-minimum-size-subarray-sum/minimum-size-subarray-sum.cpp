class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int resultLen = INT_MAX, n = nums.size();
        int sum = 0;
        int low = 0, high = 0;
        while(high < n) {
            sum = sum + nums[high];
            cout << " " << sum;
            while(sum >= target) {
                int len = (high - low) + 1;
                resultLen = min(resultLen, len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        return resultLen == INT_MAX ? 0 : resultLen;
    }
};