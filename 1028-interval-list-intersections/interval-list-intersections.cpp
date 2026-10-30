class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size(), m = secondList.size();
        if (n == 0 || m == 0)
            return res;
        int i = 0, j = 0;
        while (i < n && j < m) {
            int start1 = firstList[i][0], end1 = firstList[i][1];
            int start2 = secondList[j][0], end2 = secondList[j][1];
            if (start1 <= start2) {
                if (end1 >= start2) {
                    int interStart = max(start1, start2);
                    int interEnd = min(end1, end2);

                    res.push_back({interStart, interEnd});
                }
            } else {
                if (end2 >= start1) {
                    int interStart = max(start1, start2);
                    int interEnd = min(end1, end2);

                    res.push_back({interStart, interEnd});
                }
            }
            if (end1 <= end2) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};