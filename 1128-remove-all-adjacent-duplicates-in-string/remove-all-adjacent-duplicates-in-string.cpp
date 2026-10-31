class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        stack<char> st;
        if(s.length() == 0) return res;
        if(s.length() == 1) return s;
        for(int i=0;i<s.length();i++) {
            if(st.empty()) {
                st.push(s[i]);
            } else if(st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            char ch = st.top();
            st.pop();
            res = ch + res;
        }

        return res;
    }
};