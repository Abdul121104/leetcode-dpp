class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {}
    void s1tos2(){
        if (s2.empty()){
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        s1tos2();
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    int peek() {
        s1tos2();
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
