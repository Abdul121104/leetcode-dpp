class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        vector<int> v(26,0);
        int mx = 0;
        for(int i=0;i<sz;i++){
            v[tasks[i]-'A']++;
            mx = max(mx,v[tasks[i]-'A']);
        }
        int ans = (mx-1)*(n+1);
        for(auto i:v){
            if(i==mx) ans++;
        }
        return max(sz,ans);
    }
};
