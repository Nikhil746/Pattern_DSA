class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        // unordered_map<int, int> m1;

        for (int i = 0; i < 2*n; i++) {
            while (!st.empty() && nums[i%n] > nums[st.top()]) {
                res[st.top()] = nums[i%n];
                st.pop();
            }
            if(i < n) st.push(i);
        }

        // for (int i = 0; i < n; i++) {
        //     res.push_back(m1.count(nums[i]) ? m1[nums[i]] : -1);
        // }

        return res;
    }
};