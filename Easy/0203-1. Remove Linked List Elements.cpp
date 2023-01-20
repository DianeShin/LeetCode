/* 
Question link : https://leetcode.com/problems/remove-linked-list-elements/

Runtime : 22 ms
Beats : 88.48%
Memory : 15.1 MB
Beats : 52.8%

Time Complexity : O(n)
-> evaluation done once for each node
-> linear number of operations per node

Space Complexity : O(n)
-> n for input list
-> 2 for curr_node and prev_node

Algorithm :
1. Move the head until nullptr, or head value is not equal to val.
2. set prev_node and curr_node.
3. if curr_node's val is equal to val, connect prev_node's next to curr_node's next. This gives an effect of removing curr_node.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // remove values until the head is not equal to val
        while(head != nullptr){
            // head is equal to val, so set head to next ListNode
            if (head -> val == val) head = head -> next;
            // head is not equal to val, so leave loop
            else break;
        }
        // either all values are removed, or the input was null
        if (head == nullptr) return head;

        // remove values in list
        ListNode* prev_node = head;
        ListNode* curr_node = head -> next;
        
        while (curr_node != nullptr){
            if (curr_node -> val == val){
                prev_node -> next = curr_node -> next;
                curr_node = curr_node -> next;   
            }           
            else{
                prev_node = prev_node -> next;
                curr_node = curr_node -> next;
            }
        }
         
        return head;
    }
};