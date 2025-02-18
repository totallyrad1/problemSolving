class MinStack{
public:
    deque<pair<int,int>> ans;
    MinStack() {
        
    }
    
    void push(int val) {
        int min = getMin();
        if(ans.empty() || min > val)
            min = val;
        ans.push_back({val,min});
    }
    
    void pop() {
        ans.pop_back();
    }
    
    int top() {
        return ans.empty() ? -1 : ans.back().first; 
    }
    int getMin() {
        return ans.empty() ? -1 : ans.back().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */