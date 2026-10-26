class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast =0, slow =0;

        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast) {
                slow = 0;
                while(slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }

                return slow;
            }
            if(fast == nums.size()) break;
        }

        return -1;
    }
};