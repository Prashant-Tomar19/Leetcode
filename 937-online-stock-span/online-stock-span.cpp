class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;
    StockSpanner() {
        idx=0;
    }
    
    int next(int price) {
        if(st.empty() || price<st.top().first){
            st.push({price,idx});
            idx++;
            return 1;
        }
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(st.empty()){
            st.push({price,idx});
            idx++;
            return idx;
        }
        int count=idx-st.top().second;
        st.push({price,idx});
        idx++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */