class Solution {
public:
    bool checkchar(char s) { return isalnum(s); }

    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;

        while (low < high) {
            while(low < high && !checkchar(s[low]))low++ ;
            while(low < high && !checkchar(s[high])) high--;

           if(tolower(s[low])!=tolower(s[high])) return false;
            low++;
            high--;
        }
        return true;
    }
};