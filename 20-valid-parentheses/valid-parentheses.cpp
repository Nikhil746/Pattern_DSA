class Solution {
public:
    bool isValid(string s) {
        // bool isCorrect = false;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else if (st.empty() &&
                       (s[i] == '}' || s[i] == ']' || s[i] == ')')) {
                return false;
            } else if (st.top() == '{' && s[i] == '}') {
                st.pop();
                continue;
            } else if (st.top() == '(' && s[i] == ')') {
                st.pop();
                continue;
            } else if (st.top() == '[' && s[i] == ']') {
                st.pop();
                continue;
            } else {
                return false;
            }
        }
        return st.size() == 0 ? true : false;
    }
};