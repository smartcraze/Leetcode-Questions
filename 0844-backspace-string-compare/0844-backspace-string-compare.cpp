class Solution {
public:
    string build(string s){
        vector<char> st;

        for(char ch : s){
            if(ch == '#'){
                if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(ch);
            }
        }

        return string(st.begin(), st.end());
    }
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};