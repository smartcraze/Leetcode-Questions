class MyQueue {
public:
    stack<int> s1;
    stack<int> temp;
    MyQueue() {
        
    }
    void push(int x) {
        while(!s1.empty()){
            int front = s1.top();
            temp.push(front);
            s1.pop();
        }

        s1.push(x);

        while(!temp.empty()){
            s1.push(temp.top());
            temp.pop();
        }

    }
    
    int pop() {
       int front = s1.top();
       s1.pop();
       return front;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty() && temp.empty();
        
    }
};

