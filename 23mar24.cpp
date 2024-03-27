class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *slow=head,*fast=head->next;
        while (fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*second=slow->next;
        slow->next=nullptr;
        ListNode*prev=nullptr;
        while(second){
            ListNode*tmp=second->next;
            second->next=prev;
            prev=second;
            second=tmp;
        }
        ListNode*first=head;
        second=prev;
        while(second){
            ListNode*tmp1=first->next;
            ListNode*tmp2=second->next;
            first->next=second;
            second->next=tmp1;
            first=tmp1;
            second=tmp2;
        }
    }
};
