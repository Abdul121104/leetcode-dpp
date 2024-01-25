class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m1;
        int ans=0;
        for(int i=0;i<s.size();i++){m1[s[i]]++;m1[t[i]]--;}
        for(auto x:m1) ans+=abs(x.second);
        return ans/2;
    }
};