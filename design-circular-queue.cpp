class MyCircularQueue {
private:
    int head, tail, size;
    vector<int> values;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        head = 0;
        tail = -1;
        size = k;
        
        values.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (tail == -1) {
            tail = head;
            values[tail] = value;
            return true;
        } else if (((tail + 1) % size) != head) {
            tail = (tail + 1) % size;
            values[tail] = value;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (tail == -1) {
            return false;
        } if (head != tail) {
            head = (head + 1) % size;
            return true;
        } else if (head == tail) {
            tail = -1;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (tail == -1)
            return -1;
        return values[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (tail == -1)
            return -1;
        return values[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (tail == -1);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (tail == -1)
            return false;
        return (((tail + 1) % size) == head);
    }
};
​
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
