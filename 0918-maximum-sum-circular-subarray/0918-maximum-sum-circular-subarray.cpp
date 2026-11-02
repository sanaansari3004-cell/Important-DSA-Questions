
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxending = 0, minending = 0;
        int maxsum = nums[0], minsum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            maxending = max(nums[i], maxending + nums[i]);
            minending = min(nums[i], minending + nums[i]);

            maxsum = max(maxsum, maxending);
            minsum = min(minsum, minending);

            total += nums[i];
        }

        if (maxsum < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};
