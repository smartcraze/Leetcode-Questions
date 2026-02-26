class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        solve(0,n-1,s);
    }
    void solve(int start ,int end ,vector<char>& s){
        if(start>end) return ;
        swap(s[start],s[end]);
        solve(start+1,end-1,s);
    }
};