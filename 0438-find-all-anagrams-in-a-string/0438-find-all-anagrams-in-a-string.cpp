class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size())
            return ans;

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);

        int psize = p.size();
        int win = s.size();

        // seedin the pCount
        for (char c : p) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < psize; i++) {
            window[s[i] - 'a']++;
        }

        if (pCount == window) {
            ans.push_back(0);
        }

        for (int i = psize; i < win; i++) {
            window[s[i] - 'a']++;
            window[s[i-psize] - 'a']--;

            if (pCount == window) {
                ans.push_back(i - psize + 1);
            }
        }

        return ans;

    }
};