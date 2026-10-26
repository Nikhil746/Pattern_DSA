class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], maxProdArr = nums[0], minProdArr = nums[0];
        for(int i=1;i<nums.size();i++) {
            int val1 = nums[i];
            int val2 = nums[i] * maxProdArr;
            int val3 = nums[i] * minProdArr;

            maxProdArr = max(val1, max(val2, val3));
            minProdArr = min(val1, min(val2, val3));

            res = max(res, max(minProdArr, maxProdArr));
        }
        return res;
    }
};