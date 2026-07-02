class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* temp = headA;

        while(temp != nullptr){

            ListNode* temp2 = headB;

            while(temp2 != nullptr){

                if(temp == temp2)
                    return temp;

                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        return nullptr;
    }
};