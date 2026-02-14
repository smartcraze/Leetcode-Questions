class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        long long sum = 0;
        int cnt = 0;
        for(int num:nums){
            sum += num;
            int mod = sum%k;
            if(mp.find(mod) != mp.end()){
                cnt+=mp[mod];
            }
            mp[mod]++;
        }
        return cnt;
    }
};