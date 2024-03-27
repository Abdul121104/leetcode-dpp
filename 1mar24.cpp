class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size(),c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') c++;
        }
        if(c>0) {s[n-1] ='1';c--;}
        for(int i=0;i<n-1;i++){
            if(c>0){
                s[i]='1';
                c--;
            }
            else s[i]='0';
        }
        return s;
    }
};
