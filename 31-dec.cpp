class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]]=i;
        }
        int maxLen = -1;
        for (int i=0;i<n;i++){
            int lastOccurrence=m[s[i]];
            if (lastOccurrence>i){
                maxLen=max(maxLen,lastOccurrence-i-1);
            }
        }
        return maxLen;
    }
};
