class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int row = 0; row < numRows; row++) {
            vector<int> cur;
            long long val = 1;

            cur.push_back(1);

            for (int col = 1; col <= row; col++) {
                val = val * (row - col + 1) / col;
                cur.push_back(val);
            }

            ans.push_back(cur);
        }

        return ans;
    }
};