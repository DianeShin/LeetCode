/* 
Question link : https://leetcode.com/problems/implement-queue-using-stacks/

Runtime : 4 ms
Beats : 30.96%
Memory : 7MB
Beats : 81.79%

Time Complexity :
push : O(1) : only need to push in main_stack.
pop : O(n) : need to remove and save n-1 elements in sub_stack, remove element, then move it back to main_queue.
top : O(n) : need to remove and save n-1 elements in sub_stack, save element, then move it back to main_queue.
empty : O(1) : only need to check positions of pointers.

Space Complexity : 
push : O(n) : 1 main_stack and 1 int.
pop : O(n) : 2 stacks and 3 for i, elem_num, result.
top : O(n) : 2 stacks and 3 for i, elem_num, result.
empty : O(n) : other than existing queue to remove, no additional space needed.

Algorithm :
push :
1. push to main_stack.
pop :
1. Save the main_stack elements to sub_stack until 1 element left(the element desired to pop). Saved elements are popped.
2. Save the left element in a separate int container, then pop it from main_stack.
3. Move the sub_stack elements to main_stack.
4. return result.
top :
1. Save the main_stack elements to sub_stack until 1 element left(the element desired to pop). Saved elements are popped.
2. Save the left element in a separate int container.
3. Move the sub_stack elements to main_stack.
4. return result.
empty :
1. Empty the main_stack.

Point :
1. When moving elem, be careful to define loop condition in prior. Stack size changes by pop, so using stack.size() in loop condition will malfunction.
*/

#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> main_stack;
    stack<int> sub_stack;

    MyQueue() {
        
    }
    
    void push(int x) {
        main_stack.push(x);
    }
    
    int pop() {
        // move n-1 elems to sub_stack
        int elem_num = main_stack.size();
        for (int i = 0; i < elem_num -1; i++){
            sub_stack.push(main_stack.top());
            main_stack.pop();
        }

        // save nth elem
        int elem = main_stack.top();

        // remove nth elem
        main_stack.pop();

        // move n-1 elem back to main_stack
        elem_num = sub_stack.size();
        for (int i = 0; i < elem_num; i++){
            main_stack.push(sub_stack.top());
            sub_stack.pop();
        }       

        // return elem
        return elem;
    }
    
    int peek() {
        // move n-1 elems to sub_stack
        int elem_num = main_stack.size();
        for (int i = 0; i < elem_num -1; i++){
            sub_stack.push(main_stack.top());
            main_stack.pop();
        }

        // save nth elem
        int elem = main_stack.top();

        // move n-1 elem back to main_stack
        elem_num = sub_stack.size();
        for (int i = 0; i < elem_num; i++){
            main_stack.push(sub_stack.top());
            sub_stack.pop();
        }       

        // return elem
        return elem;       
    }
    
    bool empty() {
        return main_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */