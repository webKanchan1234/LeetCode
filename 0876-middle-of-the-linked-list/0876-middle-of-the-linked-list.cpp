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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head;
        int cnt=0;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        // if(cnt%2==0){
        //     cnt=cnt/2+1;
        // }else{
        //     cnt/=2;
        // }
        curr=head;
        for(int i=0;i<cnt/2;i++){
            curr=curr->next;
        }
        return curr;
    }
};