class FreqStack {
    unordered_map<int, int> fmp;
    priority_queue<pair<int,int>> pq;
    vector<int> v;
    
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        fmp[x]++;
        pq.push(make_pair(fmp[x], v.size()));
        v.push_back(x);
    }
    
    int pop() {
        int x = v[pq.top().second];
        pq.pop();
        fmp[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */