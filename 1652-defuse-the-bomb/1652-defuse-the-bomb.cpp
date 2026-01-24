class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k > 0) {
                // sum of next k elements
                for (int j = 1; j <= k; j++) {
                    int idx = (i + j) % n;
                    sum += code[idx];
                }
            } else {
                // sum of previous |k| elements
                for (int j = 1; j <= -k; j++) {
                    int idx = (i - j + n) % n;
                    sum += code[idx];
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
};
