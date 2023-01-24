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
        int curr_stack_size = main_stack.size();
        for (int i = 0; i < curr_stack_size -1; i++){
            sub_stack.push(main_stack.top());
            main_stack.pop();
        }

        // save nth elem
        int elem = main_stack.top();

        // remove nth elem
        main_stack.pop();

        // move n-1 elem back to main_stack
        curr_stack_size = sub_stack.size();
        for (int i = 0; i < curr_stack_size; i++){
            main_stack.push(sub_stack.top());
            sub_stack.pop();
        }       

        // return elem
        return elem;
    }
    
    int peek() {
        // move n-1 elems to sub_stack
        int curr_stack_size = main_stack.size();
        for (int i = 0; i < curr_stack_size -1; i++){
            sub_stack.push(main_stack.top());
            main_stack.pop();
        }

        // save nth elem
        int elem = main_stack.top();

        // move n-1 elem back to main_stack
        curr_stack_size = sub_stack.size();
        for (int i = 0; i < curr_stack_size; i++){
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