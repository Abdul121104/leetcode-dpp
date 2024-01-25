class Solution {
public:
    bool isvovel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int c1=0,c2=0,mid=(s.size())/2,n=s.size();
        for(int i=0;i<mid;i++){
            if (isvovel(s[i])) c1++;
        }
        for(int i=mid;i<n;i++){
            if (isvovel(s[i])) c2++;
        }
        return c1 == c2;
    }
};