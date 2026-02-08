class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        // Dummy node to handle edge cases (like reversing from head)
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        // Step 1: Reach node before the sublist
        ListNode* nodeBeforeSublist = dummyNode;
        ListNode* currentNode = head;

        for (int pos = 1; pos < left; pos++) {
            nodeBeforeSublist = nodeBeforeSublist->next;
            currentNode = currentNode->next;
        }

        // Step 2: Reverse the sublist
        ListNode* sublistTail = currentNode;  // Will become tail after reversal
        ListNode* previousNode = nullptr;

        int nodesToReverse = right - left + 1;

        while (nodesToReverse--) {
            ListNode* nextNode = currentNode->next;

            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        // Step 3: Join the broken pieces

        // Connect node before sublist to new head of reversed part
        nodeBeforeSublist->next = previousNode;

        // Connect tail of reversed sublist to remaining list
        sublistTail->next = currentNode;

        return dummyNode->next;
    }
};
