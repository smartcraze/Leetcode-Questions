class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {        
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if(temp == NULL) return head; 
            temp = temp->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 0;
        
        while(count < k && curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        head->next = reverseKGroup(curr, k);
        
        return prev;
    }
};
