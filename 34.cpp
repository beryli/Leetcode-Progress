class Solution {
public:
    int binarySearch(vector<int>& nums, int& start, int& end, int target){
        if (start > end) {return -1;}
        
        int mid = (start + end) / 2;
        int ret;
        if (nums[mid] == target) {return mid;}
        if (nums[mid] > target) {
            end = mid - 1;
            ret = binarySearch(nums, start, end, target);}
        if (nums[mid] < target) {
            start = mid + 1;
            ret = binarySearch(nums, start, end, target);}
        
        return ret;
    }
    
    int upperBoundSearch(vector<int>& nums, int start, int end, int target){
        if (start > end) 
            {return start < nums.size() && nums[start]==target ? start : start - 1;}
        
        int mid = (start + end) / 2;
        int ret;
        if (nums[mid] == target) {
            start = mid + 1;
            ret = upperBoundSearch(nums, start, end, target);}
        else{
            end = mid - 1;
            ret = upperBoundSearch(nums, start, end, target);}
        
        return ret;
    }
    
    int lowerBoundSearch(vector<int>& nums, int start, int end, int target){
        if (start > end) 
            {return start < nums.size() && nums[start]==target ? start : start + 1;}
        
        int mid = (start + end) / 2;
        int ret;
        if (nums[mid] == target) {
            end = mid - 1;
            ret = lowerBoundSearch(nums, start, end, target);}
        else{
            start = mid + 1;
            ret = lowerBoundSearch(nums, start, end, target);}
        
        return ret;
    }
    
    vector<int> method_1(vector<int>& nums, int target){
        int start = 0, end = nums.size() - 1;
        vector<int> ret = {-1, -1};
        
        int target_pos = binarySearch(nums, start, end, target);
        if (-1 == target_pos) {return ret;}
        
        ret[0] = lowerBoundSearch(nums, start, target_pos, target);
        ret[1] = upperBoundSearch(nums, target_pos, end, target);
        
        return ret;
    }
    
    vector<int> method_2(vector<int>& nums, int target){
        int start = 0, end = nums.size() - 1;
        vector<int> ret (2, -1);
        if (nums.empty()) {return ret;}
        /* find lower bound */
        while (start < end){
            int mid = (start + end) / 2;
            if (nums[mid] < target) {start = mid + 1;}
            else {end = mid;}
        }
        if (nums[start] != target) {return ret;}
        ret[0] = start;
        /* find upper bound */
        end = nums.size() - 1;
        while (start < end){
            int mid = (start + end) / 2 + 1;
            if (nums[mid] > target) {end = mid - 1;}
            else {start = mid;}
        }
        ret[1] = start;
        return ret;
    }
     
    vector<int> searchRange(vector<int>& nums, int target) {
        // return method_1(nums, target);
        return method_2(nums, target);
    }
};