class Solution {
public:
    bool isStringSame(int sArr[], int tArr[]) {
        for (int i = 0; i < 256; i++) {
            if (sArr[i] < tArr[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low = 0, start = 0, end = INT_MAX;
        int sArr[256] = {0}, tArr[256] = {0};

        for (char c : t)
            tArr[(unsigned char)c]++;

        for (int high = 0; high < (int)s.length(); high++) {
            sArr[(unsigned char)s[high]]++;
            while (isStringSame(sArr, tArr)) {
                int len = high - low + 1;
                if (len < end) {
                    end = len;
                    start = low;
                }
                sArr[(unsigned char)s[low]]--;
                low++;
            }
        }

        return end == INT_MAX ? "" : s.substr(start, end);
    }
};