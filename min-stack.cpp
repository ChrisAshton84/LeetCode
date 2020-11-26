class MinStack {
private:
    vector<int> data;
​
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push_back(x);
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        int minVal = INT_MAX;
        for (auto &x: data)
            minVal = min(minVal, x);
        
        return minVal;
    }
};
​
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
