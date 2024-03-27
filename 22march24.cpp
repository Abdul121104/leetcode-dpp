class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while (curr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        ListNode* head2 = prev;
        while (head && head2) {
            if (head->val != head2->val)
                return false;
            if(!head||!head2) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
