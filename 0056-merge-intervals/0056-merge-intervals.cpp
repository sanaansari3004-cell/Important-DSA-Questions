class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            vector<int>& last = merged.back();
            const vector<int>& curr = intervals[i];

            if (curr[0] <= last[1]) {
                last[1] = max(last[1], curr[1]);
            } else {
                merged.push_back(curr);
            }
        }

        return merged;
    }
};                           