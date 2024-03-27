class Solution {
    int solve(int s, int n, vector<int>& ps, vector<vector<int>>& dp) {
        if(s==0) return 0;
        if(n==1) return 1e9;
        if(dp[s][n]!=-1) return dp[s][n];
        if(ps[n-1]<=s) return dp[s][n] = min(1 + solve(s-ps[n-1], n, ps, dp), solve(s, n-1, ps, dp));
        else return dp[s][n] = solve(s, n-1, ps, dp);
    }
public:
    int numSquares(int s) {
        int n = sqrt(s)+1;
        vector<int> ps(n+5);
        for(int i=0; i<n+5; i++) ps[i] = i*i;
        vector<vector<int>> dp(s+5, vector<int>(n+5,-1));
        return solve(s, n+3, ps, dp);
    }
};
