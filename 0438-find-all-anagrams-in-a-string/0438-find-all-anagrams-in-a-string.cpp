class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        vector<int>freqS(26,0),freqP(26,0);
        // build up the frequency of p
        for(char ch:p) freqP[ch-'a']++;
        int left = 0;

        for(int right = 0;right<n;right++){
            freqS[s[right]-'a']++;
            if(right - left + 1 > m){
                freqS[s[left] - 'a']--;
                left++;
            }
            if(freqS==freqP) ans.push_back(left);
        } 
        return ans;       

    }
};