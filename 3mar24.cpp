class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        int size=0;
        ListNode* ptr=head;
        while (ptr!=nullptr) {
            size++;
            ptr = ptr->next;
        }
        if (size==n){
            ptr=head->next;
            delete head;
            return ptr;
        }
        ptr=head;
        int target=size-n-1;
        for (int i=0;i<target;++i) {
            ptr = ptr->next;
        }
        ListNode* nn=ptr->next;
        ptr->next=nn->next;
        delete nn;
        return head;
    }
};
