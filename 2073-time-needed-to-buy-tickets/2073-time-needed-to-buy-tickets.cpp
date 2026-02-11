class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int c=0;
        for(int i=0; i<tickets.size(); i++){
            if(i<=k){
                c+= min(tickets[i], tickets[k]);
            } 
            else{
                c+= min(tickets[i], tickets[k]-1);
            }       
        }
        return c;
    }
};