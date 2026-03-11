class Solution {
public:
    struct cmp {
        bool operator()(pair<string,int>& a, pair<string,int>& b) {

            if(a.second == b.second)
                return a.first > b.first;  

            return a.second < b.second; 
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mpp;
        for( string s : words) mpp[s]++;

        priority_queue<
        pair<string,int>,
        vector<pair<string,int>>,
        cmp
        > pq;

        for (auto &it : mpp) {
            pq.push(it);
        }

        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};