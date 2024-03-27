class Solution {
public:
    bool ispali(string s){
        int i=0,j=s.size()-1;
        if (j<0) return false;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false; 
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(ispali(x)) return x;
        }
        return "";
}};
