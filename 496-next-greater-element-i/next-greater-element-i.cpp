class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums1.size(), m = nums2.size();
        stack<int> st;
        map<int, int> m1;
        
        for (int i = 0; i < m; i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                m1[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < n; i++) {
            res.push_back(m1.count(nums1[i]) ? m1[nums1[i]] : -1);
        }

        return res;
    }
};