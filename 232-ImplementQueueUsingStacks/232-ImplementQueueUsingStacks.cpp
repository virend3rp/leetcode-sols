// Last updated: 4/24/2026, 10:14:09 PM
class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
    
    }
    
    void push(int x) {
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        if(input.empty())
        {
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        if (input.empty()) {
      exit(0);
    }
    return input.top();
    }
    
    bool empty() {
        return input.empty();
    }
};