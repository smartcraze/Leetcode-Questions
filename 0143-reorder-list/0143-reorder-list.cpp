class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow;
        ListNode* halfhead = nullptr;

        while (temp) {
            ListNode* nextNode = temp->next;
            temp->next = halfhead;
            halfhead = temp;
            temp = nextNode;
        }

        ListNode* first = head;
        ListNode* second = halfhead;

        while (second->next) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};
