class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> pq;
        
        for (char ch : s) mpp[ch]++;

        for (auto it : mpp)
            pq.push({it.second, it.first});

        string ans;
        
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            ans += string(freq, ch);
        }
        return ans;
    }
};