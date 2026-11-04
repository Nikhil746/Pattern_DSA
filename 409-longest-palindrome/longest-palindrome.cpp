class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int res = 0;
        bool odd = false;
        for (char ch : s) {
            freq[ch]++;
        }
        
        for (auto& i : freq) {
            if ((i.second % 2) == 0) {
                res += i.second;
            } else if(i.second % 2 != 0 && !odd) {
                odd = true;
                res += i.second - 1; 
            } else {
                res += i.second - 1;
            }
        }
        return !odd ? res: res+1 ;
    }
};