class Solution {
public:
    int ans=0;
     void solve(int i,int j,string &s){
         while(i>=0 && j<s.size() && s[i]==s[j]){
            ans++;
             i--;
             j++;
         }
         return;
    }
    int countSubstrings(string s) {
     for(int i=0;i<s.size();i++){
         solve(i,i,s);
         solve(i,i+1,s);
     }
     return ans;
    }
};
