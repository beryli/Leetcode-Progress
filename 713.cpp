class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {return 0;}
        
        int ret = 0;
        int product = 1, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            product *= nums[r];
            while (product >= k) {product /= nums[l++];}
            ret += r - l + 1;
        }
        
        return ret;
    }
};