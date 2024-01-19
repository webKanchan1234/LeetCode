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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        vector<int>v;
        while(curr!=NULL && curr->next!=NULL){
            v.push_back(curr->val);
            curr=curr->next->next;
        }
        if(curr){
            v.push_back(curr->val);
        }

        curr=head->next;
        while(curr!=NULL && curr->next!=NULL){
            v.push_back(curr->val);
            curr=curr->next->next;
        }
        if(curr){
            v.push_back(curr->val);
        }
        curr=head;
        for(int i=0;i<v.size();i++){
            curr->val=v[i];
            curr=curr->next;
        }
        return head;
    }
};