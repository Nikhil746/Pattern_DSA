class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        vector<int> merged = newInterval;

        // 1. intervals that end before the new one starts
        while (i < n && intervals[i][1] < merged[0]) {
            res.push_back(intervals[i++]);
        }

        // 2. intervals that overlap with the new one: absorb them
        while (i < n && intervals[i][0] <= merged[1]) {
            merged[0] = min(merged[0], intervals[i][0]);
            merged[1] = max(merged[1], intervals[i][1]);
            i++;
        }
        res.push_back(merged);

        // 3. intervals that start after the new one ends
        while (i < n) {
            res.push_back(intervals[i++]);
        }

        return res;
    }
};