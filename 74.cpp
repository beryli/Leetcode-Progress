class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int target_pos =  -1;
        int start = 0, end = matrix.size() * matrix[0].size() - 1;
        while (start <= end){
            int mid = (start + end) / 2;
            int row = mid / matrix[0].size(), col = mid % matrix[0].size();
            int mid_value = matrix[row][col];
            if (mid_value == target) {target_pos = mid; break;}
            if (mid_value > target) {end = mid - 1;}
            if (mid_value < target) {start = mid + 1;}
        }
        
        return target_pos ==  -1 ? false : true;
    }
};