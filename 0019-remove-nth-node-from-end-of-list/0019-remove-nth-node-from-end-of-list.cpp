/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        // delete head;
        if(cnt ==n){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        temp = head;
        int count = cnt-n-1;
        while(count--){
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};