class Solution {
public:
    int solve(string &text1, string &text2, int m, int n, vector<vector<int>> &memo) {
        if(m==0||n==0) {
            return 0;
        }
        if(memo[m][n] != -1) {
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            memo[m][n]=1+solve(text1, text2, m - 1, n - 1, memo);
        }
        else{
            memo[m][n] = max(solve(text1, text2, m - 1, n, memo), solve(text1, text2, m, n - 1, memo));
        }
        return memo[m][n];
}
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return solve(text1, text2, m, n, memo);
    }
};