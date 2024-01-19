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
    ListNode* sortList(ListNode* head) {
        priority_queue<int,vector<int>,greater<int>>q;
        ListNode* curr=head;
        while(curr!=NULL){
            q.push(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(!q.empty()){
            curr->val=q.top();
            q.pop();
            curr=curr->next;
        }
        return head;
    }
};