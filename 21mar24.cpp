class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nex,*prev,*curr;
        curr=head;
        prev=NULL;
        while (curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head = prev;
        return head;
    }
};
