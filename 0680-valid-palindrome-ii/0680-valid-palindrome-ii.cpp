class Solution {
public:
    bool validate(string &s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;

        while (low < high) {
            if (s[low] == s[high]) {
                low++;
                high--;
            } else {
                // Try skipping either left or right character
                return validate(s, low + 1, high) ||
                       validate(s, low, high - 1);
            }
        }
        return true;
    }
};
