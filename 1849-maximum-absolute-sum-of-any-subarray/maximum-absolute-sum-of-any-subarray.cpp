class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int res = abs(arr[0]), posSum = arr[0], negSum = arr[0];

        for(int i=1;i<arr.size();i++) {
            int val1 = arr[i];
            int val2 = arr[i] + posSum;
            int val3 = arr[i] + negSum;

            posSum = max(val1, val2);
            negSum = min(val1, val3);

            res  = max(res, max(posSum, abs(negSum)));
        }
        return res;
    }
};