class OrderedStream {
private:
    vector<bool> buf_valid;
    vector<string> buf_str;
    size_t index;
​
public:
    OrderedStream(int n) {
        buf_valid.assign(n, false);
        buf_str.assign(n, string("     "));
        index = 0; // Next element to start a return pattern from
    }
    
    vector<string> insert(int id, string value) {
        buf_valid[id - 1] = true;
        buf_str[id - 1] = value;
        
        if (buf_valid[index]) {
            size_t end = index + 1;
            
            while (buf_valid[end] && (end < buf_valid.size()))
                end++;
            
            auto start = index;
            index = end;
            
            return vector<string>(buf_str.begin() + start, buf_str.begin() + end);
        } else
            return vector<string>();
    }
};
​
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
