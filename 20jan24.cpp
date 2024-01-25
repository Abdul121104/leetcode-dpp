class Solution{
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> nse1(n),nse2(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nse1[i] = i;
            else nse1[i] = i - st.top() - 1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) nse2[i] = n - i - 1;
            else nse2[i] = st.top() - i - 1;
            st.push(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long curr_val = arr[i];
            long long left_val = nse1[i] + 1;
            long long right_val = nse2[i] + 1;
            ans += ((curr_val * ((left_val * right_val) % mod)) % mod);
            ans %= mod;
        }
        return ans;
    }
};