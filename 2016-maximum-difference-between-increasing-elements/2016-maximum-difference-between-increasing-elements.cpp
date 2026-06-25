class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxDiff = 0;

        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - minSoFar;
            maxDiff = max(maxDiff, diff);
            minSoFar = min(minSoFar, nums[i]);
        }

        return (maxDiff == 0) ? -1 : maxDiff;
    }
};