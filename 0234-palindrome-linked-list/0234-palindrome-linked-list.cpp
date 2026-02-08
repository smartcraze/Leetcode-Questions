
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* curr = head;
        ListNode* newHead = NULL;

        while (curr != NULL) {
            ListNode* newNode = new ListNode(curr->val);
            newNode->next = newHead;
            newHead = newNode;
            curr = curr->next;
        }

        while (head && newHead) {
            if (head->val != newHead->val)
                return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};