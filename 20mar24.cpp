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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1;
        ListNode *end2 = list2;
        while(end2->next!=NULL)
            end2 = end2->next;
        for(int i=0; i<a-1; i++)
            list1 = list1->next;
        ListNode *start1 = list1->next;
        for(int i=0; i<(b-a)+1;i++)
            start1=start1->next;
        list1->next=list2;
        end2->next=start1;
        return head;
    }
};
