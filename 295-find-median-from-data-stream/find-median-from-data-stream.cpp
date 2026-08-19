class MedianFinder {
public:
    priority_queue<int,vector<int>>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    int median;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(pq1.size()!=0 && num>pq1.top()){
            pq2.push(num);
        }
        else if(pq1.size()==0){
            pq1.push(num);
        }
        else{
            pq1.push(num);
        }
        if(pq1.size()>pq2.size()+1){
            int temp=pq1.top();
            pq2.push(temp);
            pq1.pop();
        }
        else if(pq2.size()>pq1.size()){
            int temp=pq2.top();
            pq1.push(temp);
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            double one=pq1.top();
            double two=pq2.top();
            return (one+two)/2;
        }
        else{
            return pq1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */