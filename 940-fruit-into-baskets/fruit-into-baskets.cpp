class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int n = fruits.size(), low = 0, high = 0, res = -1;

        while (high < n) {
            map[fruits[high]]++;
            while (map.size() > 2) {
                map[fruits[low]]--;
                if (map[fruits[low]] == 0) {
                    map.erase(fruits[low]);
                }
                low++;
            }
            int len = (high - low) + 1;
            res = max(res, len);
            high++;
        }
        return res;
    }
};