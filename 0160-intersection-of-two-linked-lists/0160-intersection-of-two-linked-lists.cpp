/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>s;
        ListNode* curr=headA;
        while(curr!=NULL){
            s.insert(curr);
            curr=curr->next;
        }
        curr=headB;
        while(curr!=NULL){
            if(s.find(curr)!=s.end()){
                return curr;
            }
            s.insert(curr);
            curr=curr->next;
        }
        return NULL;
    }
};