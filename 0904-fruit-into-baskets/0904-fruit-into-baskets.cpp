class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int j = 0;
        int count = 0;
        for(int i = 0;i<fruits.size();i++){
            mpp[fruits[i]]++;
            if(mpp.size()>2){
                mpp[fruits[j]]--;
                if(mpp[fruits[j]] ==0){
                    mpp.erase(fruits[j]);
                }
                j++;
            }
            count = max(count , i-j+1);
        }
        return count;
    }
};