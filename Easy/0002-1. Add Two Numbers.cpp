/* 
Question link : https://leetcode.com/problems/add-two-numbers/

Runtime : 76 ms
Beats : 23.61%
Memory : 71.4 MB
Beats : 82.74%

Time Complexity : O(n)
-> n represents the number of nodes of the longer number. Calculation is done until the end of the longer number.

Space Complexity : O(n)
-> creating a new linked list with a length of n(+1)

Algorithm :
1. From left, choose one element.
2. With a nested loop, choose the next element that's on the right side of left element.
3. Check if the sum of two elements equal to target.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* tail = result;
        ListNode* curr_l1 = l1;
        ListNode* curr_l2 = l2;
        bool carry_on = false;

        while (true){
            int sum;
            if(curr_l1 == nullptr && curr_l2 == nullptr){
                if (carry_on){
                    sum = 1;
                ListNode* temp = new ListNode(sum);
                tail -> next = temp;
                tail = tail -> next;
                } 
                break;
            }
            else if (curr_l1 == nullptr){
                sum = curr_l2 -> val + carry_on;
                if (sum >= 10){
                    sum -= 10;
                    carry_on = true;
                }
                else{
                    carry_on = false;
                }
                curr_l2 = curr_l2 -> next;
            }
            else if (curr_l2 == nullptr){
                sum = curr_l1 -> val + carry_on;
                if (sum >= 10){
                    sum -= 10;
                    carry_on = true;
                }
                else{
                    carry_on = false;
                }
                curr_l1 = curr_l1 -> next;
            }
            else{
                sum = curr_l1 -> val + curr_l2 -> val + carry_on;
                if (sum >= 10){
                    sum -= 10;
                    carry_on = true;
                }
                else{
                    carry_on = false;
                }
                curr_l1 = curr_l1 -> next;
                curr_l2 = curr_l2 -> next;
            }
            ListNode* temp = new ListNode(sum);
            tail -> next = temp;
            tail = tail -> next;
        }
        return result -> next;
    }     
};