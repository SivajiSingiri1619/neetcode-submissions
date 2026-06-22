class MinStack {
public:
    stack<int>st;
    stack<int>min_st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(min_st.empty() || min_st.top() >= value) min_st.push(value);
        st.push(value);
    }
    
    void pop() {
        if(!st.empty()){

             if(st.top() == min_st.top()) min_st.pop();
             st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
