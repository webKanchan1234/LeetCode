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
        ListNode* curr=list1;
        ListNode* curr1=list2;
        for(int i=0;i<a-1;i++){
            curr=curr->next;
        }
        ListNode* l2=curr->next;
        for(int i=0;i<b-a+1;i++){
            l2=l2->next;
        }

        curr->next=list2;
        while(curr1->next){
            curr1=curr1->next;
        }
        curr1->next=l2;
        return list1;
    }
};