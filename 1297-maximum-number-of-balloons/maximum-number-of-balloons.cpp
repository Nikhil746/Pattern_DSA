class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int formation = INT_MAX;
        unordered_map<char, int> hmap;
        unordered_map<char, int> balloon;
        string sample = "balloon";
        for (char c : sample) {
            balloon[c]++;
        }
        for (char c : text) {
            hmap[c]++;
        }

        for (auto& i : balloon) {
            char ch = i.first;
            auto val = hmap.find(ch);
            if (val == hmap.end() || val->second < i.second) {
                return 0;
            }
            int cal = val->second / i.second;
            formation = min(cal, formation);
        }
        return formation;
    }
};