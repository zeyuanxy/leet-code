class Stack {
private:
    queue<int> q1, q2;
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.pop();
        swap(q1, q2);
    }

    // Get the top element.
    int top() {
        int x = 0;
        while (!q1.empty()) {
            x = q1.front();
            q1.pop();
            q2.push(x);
        }
        swap(q1, q2);
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};