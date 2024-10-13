class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int maxx = INT_MIN;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], {i, 0}});
            maxx = max(maxx, nums[i][0]);
        }
        int range = INT_MAX;
        vector<int> ans(2);
        while (true) {
            int smallestNumber = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            if (maxx - smallestNumber < range) {
                range = maxx - smallestNumber;
                ans[0] = smallestNumber;
                ans[1] = maxx;
            }
            pq.pop();
            if (j + 1 < nums[i].size()) {
                pq.push({nums[i][j + 1], {i, j + 1}});
                maxx = max(maxx, nums[i][j + 1]);
            } else
                break;
        }
        return ans;
    }
};