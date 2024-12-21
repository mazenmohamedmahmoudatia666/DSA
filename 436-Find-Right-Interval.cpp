class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> starts, res;
        int n = intervals.size();

        // Collect start times
        for (auto& interval : intervals) {
            starts.push_back(interval[0]);
        }
        // 3 2 1

        // Sort starts to prepare for binary search
        vector<pair<int, int>> sorted_starts;
        for (int i = 0; i < n; ++i) {
            sorted_starts.push_back({intervals[i][0], i});
            // 3, 0  2,1   1,2
        }
        sort(sorted_starts.begin(), sorted_starts.end());

        // Find right intervals
        for (int i = 0; i < n; ++i) {
            int end_time = intervals[i][1];
            auto it = lower_bound(sorted_starts.begin(), sorted_starts.end(), make_pair(end_time, 0));

            if (it != sorted_starts.end()) {
                res.push_back(it->second);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};
