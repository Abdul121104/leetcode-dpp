class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n=v.size(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                ans+=min(v[i],v[i+1]);
            }
        }
        return ans;
    }
};
