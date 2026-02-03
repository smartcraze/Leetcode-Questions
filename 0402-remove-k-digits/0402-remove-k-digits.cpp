class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        // Step 1: Greedy removal using monotonic stack idea
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // Step 2: If k still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Step 3: Remove leading zeros
        int idx = 0;
        while (idx < st.size() && st[idx] == '0') idx++;

        string ans = st.substr(idx);

        // Step 4: Edge case
        return ans.empty() ? "0" : ans;
    }
};
