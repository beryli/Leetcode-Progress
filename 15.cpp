class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // cout << nums.size() - 2;
        vector<vector<int>> ret;
        int n = nums.size(), l, r, sum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (n - 2); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {continue;}
            l = i+1, r = n-1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) {l++;}
                else if (sum > 0) {r--;}
                else {
                    ret.push_back(vector<int>{nums[i], nums[l] ,nums[r]});
                    while (l+1 < r && nums[l] == nums[l+1]) {l++;}
                    while (r-1 > l && nums[r] == nums[r-1]) {r--;}
                    l++; r--;
                }
            }
        }
        return ret;
    }
};