class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int i = 0, j = 0;
        int arrow = 0;
        while (i < n && j < n) {
            int x1 = points[i][0];
            int x2 = points[i][1];
            while (j < n && points[j][0] >= x1 && points[j][0] <= x2) {
                x1 = max(x1, points[j][0]);
                x2 = min(x2, points[j][1]);
                j++;
            }
            arrow++;
            i = j;
        }
        return arrow;
    }
};