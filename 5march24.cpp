class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length()-1;
        char curr = s[i];
        while (i<j){
            if(s[i]==curr&&s[j]==curr) {
                while (i<=j&&s[i]==curr) i++;
                while (i<=j&&s[j]==curr) j--;
                curr = s[i];
            }
            else{
                break;
            }
        }
        return max(0,j-i+1);
    }
};
