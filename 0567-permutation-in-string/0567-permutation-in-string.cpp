class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> window;
        unordered_map<char, int> freq;
        for (char ch : s1)
            freq[ch]++;
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            window[s2[right]]++;

            while (right - left + 1 > s1.size()) {
                window[s2[left]]--;
                if (window[s2[left]] == 0) {
                    window.erase(s2[left]);
                }
                left++;
            }
            if (window == freq)
                return true;
        }
        return false;
    }
};