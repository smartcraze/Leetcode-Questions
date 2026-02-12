
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        ListNode dummy(0);
        ListNode* curr = &dummy;

        for (int x : arr) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        return dummy.next;
    }
};