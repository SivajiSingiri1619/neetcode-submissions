class MyQueue {
public:
   deque<int>dq;
    MyQueue() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        
        int val = 0;
        if(!dq.empty()){
            val = dq.front();
            dq.pop_front();
        }
        return val;
    }
    
    int peek() {
        return dq.front();
    }
    
    bool empty() {
        return dq.empty();
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