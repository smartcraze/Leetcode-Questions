class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> ans;
        stack<pair<int,int>> st;         
        int index = 0;
        while (head) {
            ans.push_back(0);
            while (!st.empty() && st.top().first < head->val) {
                ans[st.top().second] = head->val;
                st.pop();
            }
            
            st.push({head->val, index});
            
            head = head->next;
            index++;
        }
        
        return ans;
    }
};