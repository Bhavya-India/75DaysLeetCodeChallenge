class MyQueue {
private:
    stack<int> inbox;   // for push
    stack<int> outbox;  // for pop/peek

    // Move all from inbox → outbox (only when outbox empty)
    void transfer() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inbox.push(x);          // always push to inbox
    }

    int pop() {
        transfer();              // ensure outbox has elements
        int front = outbox.top();
        outbox.pop();
        return front;
    }

    int peek() {
        transfer();              // ensure outbox has elements
        return outbox.top();
    }

    bool empty() {
        return inbox.empty() && outbox.empty();
    }
};
