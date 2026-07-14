class MyQueue {
public:
    stack<int>st;
    stack<int>st2;
    int rear,front;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st.empty()){
                int temp=st.top();
                st.pop();
                st2.push(temp);
            }
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st.empty()){
                int temp = st.top();
                st.pop();
                st2.push(temp);
            }
        }
        return st2.top();
    }
    
    bool empty() {
        if(st.empty() && st2.empty()){
            return true;
        }
        return false;
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