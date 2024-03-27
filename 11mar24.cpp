class Solution {
public:
    string customSortString(string order, string s) {
            map<char,int> m;
            string ans="";
            for(char i: s) m[i]++;
            for(char i: order){
            if(m[i]){
            while(m[i]){
            ans+=i;
            m[i]--;
            }
            }
            }
    for(char i: s)
        if(m[i])
            ans+=i;
    
    return ans;
            
    
}
};
