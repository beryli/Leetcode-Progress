class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        int sum = 0, l = 0;
        for (int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while (sum >= target) {
                ret = min(ret, r-l+1);
                sum -= nums[l++];
            }
            // while (sum - nums[l] >= target) { sum -= nums[l++];}
            // if (sum >= target && ret > r - l + 1) {ret = r - l + 1;}
        }
        return ret != INT_MAX ? ret : 0;
    }
};