/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k == 1)
            return head;
        int cnt = 0, groupNodeCnt = 0;
        ListNode prev = null, first = null, dup = head, prevGroupFirst = null, ans = null;
        int size = 0;
        while(dup != null){
            size++;
            dup = dup.next;
        }
        int extraNodes = size - (size/k)*k;
        while(head != null){
            if(size-cnt == extraNodes)
                break;
            if(groupNodeCnt == 0){
                first = head; 
            }
            else if(groupNodeCnt == k-1){
                first.next = head.next;
                if(ans == null)
                    ans = head;
                if(prevGroupFirst != null){
                    prevGroupFirst.next = head;
                }
                prevGroupFirst = first;
            }
            ListNode nextNode = head.next;
            head.next = prev;
            prev = head;
            head = nextNode;
            cnt++;
            groupNodeCnt++;
            groupNodeCnt %= k;
        }
        return ans;
    }
}
