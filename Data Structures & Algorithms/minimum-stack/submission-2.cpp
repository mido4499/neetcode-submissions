class MinStack {
private:
    stack<int> theStack;
    stack<int> minStack;
    int min;
public:
    MinStack() {
        min = numeric_limits<int>::max();    
    }
    
    void push(int val) {
        min = std::min(min, val);
        theStack.push(val);
        minStack.push(min);
    }
    
    void pop() {
        theStack.pop();
        minStack.pop();
        min = (minStack.empty())?numeric_limits<int>::max():minStack.top();
    }
    
    int top() {
        int val = theStack.top();
        return val;
    }
    
    int getMin() {
        return minStack.top();
    }
};
