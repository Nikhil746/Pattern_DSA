class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int>map;
        map[0] = 1;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            int prevsum = sum - k;
            if(map.count(prevsum)) {
                count += map[prevsum];
            }
            map[sum]++;
        }

        return count;
    }
};