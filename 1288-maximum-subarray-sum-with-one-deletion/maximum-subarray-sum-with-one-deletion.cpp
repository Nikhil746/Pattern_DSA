class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int oneDelete = INT_MIN, noDelete = arr[0], res = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNo = noDelete, prevOne = oneDelete;

            noDelete = max(arr[i], prevNo + arr[i]);

            // delete arr[i], or delete something earlier and extend
            oneDelete = prevNo;
            if (prevOne != INT_MIN)
                oneDelete = max(oneDelete, prevOne + arr[i]);

            res = max(res, max(noDelete, oneDelete));
        }
        return res;
    }
};