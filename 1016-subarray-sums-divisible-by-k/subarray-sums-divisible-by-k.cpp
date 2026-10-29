class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), count = 0;
        unordered_map<int, int> hmap;
        hmap[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            rem = rem < 0 ? rem + k : rem;
            if(hmap.count(rem) ) {
               count += hmap[rem];
            }

            hmap[rem]++;
        }

        return count;
    }
};