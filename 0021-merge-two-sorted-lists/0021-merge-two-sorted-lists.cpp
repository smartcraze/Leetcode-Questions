class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* prehead = new ListNode(-1);
        ListNode* curr = prehead;

        while(list1 != nullptr && list2 != nullptr){
            
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;   // FIXED
            }

            curr = curr->next;
        }

        if(list1 != nullptr){
            curr->next = list1;
        }
        else{
            curr->next = list2;
        }

        return prehead->next;
    }
};
