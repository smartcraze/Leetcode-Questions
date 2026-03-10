class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            int nextStart = intervals[i][0];
            int nextEnd   = intervals[i][1];
            if (nextStart <= current[1]) {
                current[1] = max(current[1], nextEnd);
            }
            else {
                merged.push_back(current);
                current = intervals[i];
            }
        }
        merged.push_back(current);
        return merged;
    }
};