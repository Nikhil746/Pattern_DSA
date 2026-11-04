class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        int n = ransomNote.length(), m = magazine.length();
        for (int i = 0; i < n; i++) {
            freq1[ransomNote[i]]++;
        }
        for (int i = 0; i < m; i++) {
            freq2[magazine[i]]++;
        }
        // if (freq1.size() != freq2.size())
        //     return false;

        for (auto& p : freq1) {
            auto it = freq2.find(p.first);
            if (it == freq2.end() || it->second < p.second) {
                return false;
            }
        }
        return true;
    }
};