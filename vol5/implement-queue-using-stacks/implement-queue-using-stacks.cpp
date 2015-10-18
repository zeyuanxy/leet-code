class Queue {
private:
    stack<int> in_stack, out_stack;
    // Pop every element from in_stack to out_stack
    void fromInToOut() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                int x = in_stack.top();
                in_stack.pop();
                out_stack.push(x);
            }
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        in_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        fromInToOut();
        out_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        fromInToOut();
        return out_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in_stack.empty() && out_stack.empty();
    }
};