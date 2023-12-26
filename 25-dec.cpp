class Solution {
public:
    int way(string s, int index, vector<int>& memo) {
        if (index == s.length()) return 1;
        if (s[index] == '0')  return 0;
        if (memo[index] != -1) return memo[index];
        int ways=way(s, index + 1, memo);
        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
            ways += way(s, index + 2, memo);
        return memo[index] = ways;
    }
    int numDecodings(string s){
        vector<int> memo(s.length(), -1);
        return way(s,0,memo);
    }
};
