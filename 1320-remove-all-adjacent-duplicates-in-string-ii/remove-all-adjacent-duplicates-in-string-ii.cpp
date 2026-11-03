class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.length();
        pair<char, int> charPair;
        string res = "";

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (st.empty()) {
                st.push({c, 1});
                continue;
            } else if (st.top().first != c) {
                st.push({c, 1});
                continue;
            } else if (st.top().first == c && st.top().second < (k-1)) {
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second+1});
                continue;
            } else {
                st.pop();
            }
        }

        while (!st.empty()) {
            for (int i = 0; i < st.top().second; i++) {
                res += st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};