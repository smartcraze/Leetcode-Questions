class Solution {
public:
    string makeGood(string s) {
        vector<char>st;
        for(char ch : s){
            if(!st.empty() && abs(st.back() - ch) == 32) st.pop_back();
            else st.push_back(ch);
        }
        return string(st.begin(),st.end());
        
    }
};