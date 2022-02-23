class Solution {
public:
    int method_1 (vector<int>& height) {
        int max_area = 0, min_width = 0, area;
        for (int i = 0; i < height.size(); i++){
            if (height[i] == 0) {continue;}
            
            if (max_area != 0) {min_width = max_area / height[i];}
            
            for (int j = height.size() - 1; j > i + min_width; j--){
                area = (j - i) * min(height[i], height[j]);
                if (area > max_area) {max_area = area;}
            }
        }
        return max_area;
    }
    
    int method_2 (vector<int>& height) {
        int max_area = 0, area;
        int i = 0, j = height.size() -1;
        while (i < j) {
            area = (j - i) * min(height[i], height[j]);
            max_area = max(max_area, area);
            height[i] < height[j] ? i++ : j--;
        }
        return max_area;
    }
    
    int maxArea(vector<int>& height) {
        // return method_1(height);
        return method_2(height);
    }
};