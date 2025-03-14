class MinStack {
    private:
        stack<int> s;
        stack<int> mins;

    public:
        MinStack() {

        }
        
        void push(int val) {
            if (s.empty() || val <= mins.top()) {
                mins.push(val);
            }
            s.push(val);
        }
        
        void pop() {
            if (s.top() == mins.top()) {
                mins.pop();
            }
            s.pop();
        }
        
        int top() {
            return s.empty() ? -1 : s.top();
        }
        
        int getMin() {
            return mins.empty() ? -1 : mins.top();
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