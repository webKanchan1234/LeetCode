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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* loop=NULL;
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                loop=fast;
                break;
            }
        }
        if(!loop) return NULL;
        while(head!=loop){
            head=head->next;
            loop=loop->next;
        }
        return head;
    }
};