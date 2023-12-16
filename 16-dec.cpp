class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int c[26]={0},i;
        for(i=0;i<s.length();i++){
            c[s[i]-'a']++;
            c[t[i]-'a']--;
        }
        for(i=0;i<26;i++)if(c[i]!=0)return false;
        return true;
    }
};
