class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        
        head = dummy->next;

        delete dummy;
        return head;
    }
};