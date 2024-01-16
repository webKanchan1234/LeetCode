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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int cnt=0;
        ListNode* curr=head;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        if(cnt==n){
            return head->next;
        }
        curr=head;
        ListNode* prev=head;
        for(int i=1;i<cnt-n+1;i++){
            cout<<curr->val<<" ";
            cout<<prev->val<<" ";
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete(curr);
        return head;
    }
};