class MovingAverage {
private:
    queue<int> q;
    int s;
    double s_d;
    int sum;
​
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : s(size), sum(0), s_d(size) {
    }
    
    double next(int val) {
        if (q.size() == s) {
            sum -= q.front();
            q.pop();
        
            sum += val;
            q.push(val);
​
            return sum / s_d;
        }
        
        sum += val;
        q.push(val);
        
        return sum / (double)(q.size());
    }
};
​
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
