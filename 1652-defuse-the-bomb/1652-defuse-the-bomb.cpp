class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        int windowSum = 0;
        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                windowSum += code[j % n];
            }
            for (int i = 0; i < n; i++) {
                ans[i] = windowSum;
                windowSum -= code[(i + 1) % n];
                windowSum += code[(i + k + 1) % n];
            }
        }
        else {
            int kk = -k;
            for (int j = 1; j <= kk; j++) {
                windowSum += code[(n - j) % n];
            }
            for (int i = 0; i < n; i++) {
                ans[i] = windowSum;
                windowSum -= code[(i - kk + n) % n];
                windowSum += code[i % n];
            }
        }
        return ans;
    }
};
