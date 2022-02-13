class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        Every point in [start, end] (included) is a peak nominee. 
        That is, `nums[start - 1] < nums[start]` and `nums[end] > nums[end + 1]`. 
        */
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < nums[mid + 1]) {start = mid + 1;}
            else {end = mid;}
        }
        return start;
    }
};