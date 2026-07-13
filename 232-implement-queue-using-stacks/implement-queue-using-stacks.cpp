class MyQueue {
public:
    int arr[100000];
    int top_index,front;
    MyQueue() {
        top_index=-1;
        front=0;
    }
    
    void push(int x) {
        arr[++top_index]=x;
    }
    
    int pop() {
        return arr[front++];
    }
    
    int peek() {
        return arr[front];
    }
    
    bool empty() {
        return front>top_index;
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