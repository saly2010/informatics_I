#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in_stack;
    stack<int> out_stack;

    void shiftStacks() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        shiftStacks();
        int front = out_stack.top();
        out_stack.pop();
        return front;
    }
    
    int peek() {
        shiftStacks();
        return out_stack.top();
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};
