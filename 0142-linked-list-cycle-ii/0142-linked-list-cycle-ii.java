/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;

        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;

            if(slow==fast){
                ListNode pt1=head;
                ListNode pt2=slow;

                while(pt1!=pt2){
                    pt1=pt1.next;
                    pt2=pt2.next;
                }
                return pt1;
            }
        }
        return null;
    }
}