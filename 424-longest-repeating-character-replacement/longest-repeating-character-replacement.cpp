class Solution {
public:
    int findChar(int arr[]) {
        int maxFreq = 0;
        for (int i = 0; i < 256; i++) {
            maxFreq = max(maxFreq, arr[i]);
        }
        return maxFreq;
    }
    int characterReplacement(string s, int k) {
        int arr[256] = {0};
        int low = 0, high = 0, res = INT_MIN, n = s.length();
        while (high < n) {
            arr[(int)s[high]]++;
            int len = (high - low) + 1;
            int maxCharFreq = findChar(arr);
            int diff = len - maxCharFreq;

            while (diff > k) {
                arr[s[low]]--;
                low++;
                len = (high - low) + 1;
                maxCharFreq = findChar(arr);
                diff = len - maxCharFreq;
            }
            res = max(res, len);
            high++;
        }
        return res;
    }
};