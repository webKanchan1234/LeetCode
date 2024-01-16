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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        if(cnt==1){
            return NULL;
        }
        curr=head;
        
        cnt=cnt/2-1;
        while(cnt>0){
            curr=curr->next;
            cnt--;
        }
        curr->next=curr->next->next;
        return head;
    }
};