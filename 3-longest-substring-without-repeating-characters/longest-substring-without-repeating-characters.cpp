class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0, res = 0, n = s.length();
        unordered_map<char, int> map;
        while (high < n) {
            map[s[high]]++;
            int len = (high - low) + 1;
            while (map.size() < len) {
                map[s[low]]--;
                if (map[s[low]] == 0) {
                    map.erase(s[low]);
                }
                low++;
                len = (high - low) + 1;
            }
            res = max(res, len);
            high++;
        }
        return res;
    }
};