class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int i = 0, j = 0, start, end;
        while (i < firstList.size() && j < secondList.size()) {
            start = firstList[i][0] > secondList[j][0] ? firstList[i][0] : secondList[j][0];
            end = firstList[i][1] < secondList[j][1] ? firstList[i][1] : secondList[j][1];
            if (start <= end) {ret.push_back(vector<int>{start, end});}
            firstList[i][1] < secondList[j][1] ? i++ : j++;
        }
        return ret;
    }
};