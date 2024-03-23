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
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        ListNode* curr=head;
        while(curr!=NULL){
            v.push_back(curr);
            curr=curr->next;
        }
        int n=v.size()-1;
        curr=head;
        int i=0;
        while(i<n){
            v[i]->next=v[n];
            i++;
            if(i==n) break;
            v[n]->next=v[i];
            n--;
        }
        v[i]->next=NULL;
    }
};