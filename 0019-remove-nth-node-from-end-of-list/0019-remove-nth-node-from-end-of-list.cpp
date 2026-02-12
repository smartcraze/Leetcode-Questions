class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumy = new ListNode(0);
        dumy->next = head;
        ListNode* fast = dumy;
        ListNode* slow = dumy;

        for (int i = 0; i< n;i++){
            fast = fast->next;
        }

        while(fast->next!=nullptr){
            fast= fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return dumy->next;
    }
};