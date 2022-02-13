class Solution {
public:
    
    int rotateSearch(vector<int>& nums, int start, int end){
        /* Because there is no target, end - start must be 1 in the end and won't be 0. */
        if (end - start == 1) {return end;}
        int ret;
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) {ret = rotateSearch(nums, mid, end);}
        if (nums[mid] < nums[end]) {ret = rotateSearch(nums, start, mid);}
        return ret;
    }
    
    int binarySearch(vector<int>& nums, int start, int end, int target){
        if (start > end) {return -1;}
        
        int ret;
        int mid = (start + end) / 2;
        if (nums[mid] == target) {return mid;}
        if (nums[mid] < target) {ret = binarySearch(nums, mid + 1, end, target);}
        if (nums[mid] > target) {ret = binarySearch(nums, start, mid - 1, target);}
        return ret;
    }
    
    int method_1(vector<int>& nums, int target){
        int ret = -1;
        int start = 0, end = nums.size() - 1;
        /* search for rotate */
        int rotate_code = 0;
        if (nums[start] > nums[end]) {
            rotate_code = rotateSearch(nums, start, end);
            rotate(nums.begin(), nums.begin() + rotate_code, nums.end());
        }
        /* binary search */
        start = 0, end = nums.size() - 1;
        int index_without_rotate = binarySearch(nums, start, end, target);
        if (index_without_rotate == -1) {return ret;}
        /* calibration */
        if (index_without_rotate < nums.size() - rotate_code) 
            {ret = index_without_rotate + rotate_code;}
        else {ret = index_without_rotate - (nums.size() - rotate_code);}
        return ret;
    }
    
    int method_2(vector<int>& nums, int target){
        /* handle rotate */
        int start = 0, end = nums.size() - 1;
        while (start < end){
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {start = mid + 1;}
            else {end = mid;}
        }
        int rotate_code = start;
        /* handle search */
        start = 0, end = nums.size() - 1;
        int ret = -1;
        while (start <= end){
            int mid = (start + end) / 2;
            int real_mid = (mid + rotate_code) % nums.size();
            if (nums[real_mid] == target) {return real_mid;}
            if (nums[real_mid] > target) {end = mid - 1;}
            else {start = mid + 1;}
        }
        return ret;
    }
        
    int search(vector<int>& nums, int target) {
        // return method_1(nums, target);
        return method_2(nums, target);
    }
};