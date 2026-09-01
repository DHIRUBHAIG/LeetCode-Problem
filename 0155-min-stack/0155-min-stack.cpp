class MinStack {
public:
//declration
vector<pair<int,int>>st;
    MinStack() {
        //contructor
        //public:
        //st;    
    }
    
    void push(int value) {
        if(st.empty()){
            st.push_back({value,value});
            return;
        }
        int curr_min=min(value,st.back().second);
        st.push_back({value,curr_min});
        
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();
        }
       // return -1;
        
    }
    
    int top() {
        return st.back().first;
        
    }
    
    int getMin() {
        if(!st.empty()){
            return st.back().second;

        }
        return -1;
        
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */