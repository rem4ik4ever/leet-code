/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    
    var n1 = l1;
    var n2 = l2;
    var res, current = new ListNode(0);
    while(n1 || n2){
        if(n1 && n2){
            if(n1.val > n2.val){
                current = new ListNode(n2.val);
                console.log(current);
                current = current.next;
                n2 = n2.next
                
            } else {
                current = new ListNode(n1.val);
                console.log(current);
                current = current.next;
                n1 = n1.next
            }
        } else {
            if(n1){
                current = new ListNode(n1.val);
                console.log(current);
                current = current.next;
                n1 = n1.next
            } else {
                current = new ListNode(n2.val);
                console.log(current);
                current = current.next;
                n2 = n2.next
            }
        }
    }
    return res;
};