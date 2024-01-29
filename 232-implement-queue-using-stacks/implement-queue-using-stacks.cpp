class MyQueue {
public:
    stack<int>q,p;
    MyQueue() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(p.empty())
        {
            while(!q.empty())
            {
                    p.push(q.top());
                    q.pop();
            }
        }
        int x = p.top();
        p.pop();
        return x;
    }
    
    int peek() {
        if(p.empty())
        {
           while(!q.empty())
            {
                    p.push(q.top());
                    q.pop();
            }
        }
        int x = p.top();
        return x;
    }
    
    bool empty() {
        if(!q.empty() || !p.empty())
        {
            return false;
        }
        return true;
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