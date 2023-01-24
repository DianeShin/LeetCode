/* 
Question link : https://leetcode.com/problems/implement-stack-using-queues/

Runtime : 0 ms
Beats : 100%
Memory : 6.8MB
Beats : 75.90%

Time Complexity :
push : O(1) : only need to push in main_queue.
pop : O(n) : need to remove and save n-1 elements in sub_queue, remove element, then move it back to main_queue.
top : O(n) : need to remove and save n-1 elements in sub_queue, remove and save element, then move it back to main_queue.
empty : O(1) : only need to check positions of pointers.

Space Complexity : 
push : O(n) : 1 main_queue and 1 int.
pop : O(n) : 2 queues and 3 for i, elem_num, result.
top : O(n) : 2 queues and 3 for i, elem_num, result.
empty : O(n) : other than existing queue to remove, no additional space needed.

Algorithm :
push :
1. push to main_queue.
pop :
1. save the main_queue elements to sub_queue until 1 element left(the element desired to pop). Saved elements are popped.
2. save the left element in a separate int container, then pop it from main_queue.
3. move the sub_queue elements to main_queue.
4. return result.
top :
1. save the main_queue elements to sub_queue until 1 element left(the element desired to pop). Saved elements are popped.
2. save the left element in a separate int container, then save it to sub_queue, then pop it from main_queue.
3. move the sub_queue elements to main_queue.
4. return result.
empty :
1. empty the main_queue.

Point :
1. When moving elem, be careful to define loop condition in prior. Queue size changes by pop, so using queue.size() in loop condition will malfunction.

*/

#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> main_queue;
    queue<int> sub_queue;

    MyStack() {
        
    }
    
    void push(int x) {
        main_queue.push(x);
    }
    
    int pop() {
        // move elements to sub_queue until desired elem is left in main_queue.
        int elem_num = main_queue.size()-1;
        for(int i = 0; i < elem_num; i++){
            sub_queue.push(main_queue.front());
            main_queue.pop();
        }

        // save the result and pop.
        int result = main_queue.front();
        main_queue.pop();

        // restore elems to main_queue.
        elem_num = sub_queue.size();
        for (int i = 0; i < elem_num; i++){
            main_queue.push(sub_queue.front());
            sub_queue.pop();
        }

        // return result.
        return result;
    }
    
    int top() {
        // move elements to sub_queue until desired elem is left in main_queue.
        int elem_num = main_queue.size()-1;
        for(int i = 0; i < elem_num; i++){
            sub_queue.push(main_queue.front());
            main_queue.pop();
        }

        // save the result then move the elem to sub_queue.
        int result = main_queue.front();
        sub_queue.push(main_queue.front());
        main_queue.pop();

        // restore elems to main_queue.
        elem_num = sub_queue.size();
        for (int i = 0; i < elem_num; i++){
            main_queue.push(sub_queue.front());
            sub_queue.pop();
        }

        // return result.
        return result;       
    }
    
    bool empty() {
        return main_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */