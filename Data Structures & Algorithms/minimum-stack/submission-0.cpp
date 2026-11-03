class MinStack {
private:
    vector<pair<int, int>> v;
    int min;

public:
    MinStack() {
        this->min = INT_MAX;
    }
    
    void push(int val) {
        this->min = std::min(this->min, val);
        this->v.push_back({val, this->min});
    }
    
    void pop() {
        this->v.pop_back();
        this->min = this->v.empty() ? INT_MAX : this->v.back().second;
    }
    
    int top() {
        return this->v.back().first;
    }
    
    int getMin() {
        return this->min;
    }
};
