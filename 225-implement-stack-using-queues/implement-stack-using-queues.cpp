class MyStack {
public:
    int arr[100000];
    int front,rear;
    MyStack() {
        front=0;
        rear=0;
    }
    
    void push(int x) {
        arr[rear++]=x;
        if(rear>1){
            front++;
        }
    }
    
    int pop() {

        rear--;
        if(front==0){
            return arr[front];
        }    
        return arr[front--];
    }
    
    int top() {
        return arr[front];
    }
    
    bool empty() {
        return front==rear;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */