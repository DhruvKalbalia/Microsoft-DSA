class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i=0; i<=n; i++){
            if (fast==nullptr)
            return head;
            fast=fast->next;
        }

        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode *nodeDeleted = slow->next;
        if (nodeDeleted!=nullptr){
            slow->next = nodeDeleted->next;
        }
        delete nodeDeleted;

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};