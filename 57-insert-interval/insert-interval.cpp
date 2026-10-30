class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size(), pos = 0;
        vector<vector<int>> res;

        if (n == 0) {
            res.push_back({newInterval[0], newInterval[1]});
            return res;
        }

        int start1 = intervals[0][0], end1 = intervals[0][1];
        int interval1 = newInterval[0], interval2 = newInterval[1];
        for (int i = 0; i < n; i++) {
            start1 = intervals[i][0];
            if (start1 < interval1) {
                pos = i + 1;
            } else if (start1 > interval1)
                break;
        }
        intervals.insert(intervals.begin() + pos, {interval1, interval2});

        start1 = intervals[0][0], end1 = intervals[0][1];
        for (int i = 1; i < n + 1; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }

            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }

        res.push_back({start1, end1});
        return res;
    }
};