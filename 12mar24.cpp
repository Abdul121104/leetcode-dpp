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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        unordered_map<int, ListNode*> mp;
        int psum=0;
        ListNode* curr=temp;
        while(curr){
            psum+=curr->val;
            if(mp.find(psum)!=mp.end()){
                ListNode* prev=mp[psum];
                int pf=psum;
                ListNode* t=prev;
                while(t->next!=curr){
                    t=t->next;
                    pf+=t->val;
                    mp.erase(pf);
                }
                prev->next=curr->next;
            }
            else{
                mp[psum]=curr;
            }
            curr=curr->next;
        }
        return temp->next;
    }
};
