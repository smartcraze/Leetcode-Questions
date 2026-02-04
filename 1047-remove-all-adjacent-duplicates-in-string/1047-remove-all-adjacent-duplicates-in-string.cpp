class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for (char ch : s) {
            if (!st.empty() && st.back() == ch) {
                st.pop_back();
            }else{
                st.push_back(ch);
            }
        }
        return string(st.begin(), st.end());
    }
};