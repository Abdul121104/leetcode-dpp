class Solution {
public:
    int mod = 1000000007;

    int recursiveDP(int n, int k, std::vector<std::vector<int>>& dp) {
        if (n == 0 || k == 0) 
            return 1;
        if (dp[n][k] != -1)
            return dp[n][k];
        int val=(recursiveDP(n-1,k,dp)+mod-(k-n>=0?recursiveDP(n - 1, k - n, dp):0))%mod;
        dp[n][k]=(recursiveDP(n, k-1,dp)+val)%mod;
        return dp[n][k];
    }
    int kInversePairs(int n, int k){
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return (recursiveDP(n,k,dp)+mod-(k>0?recursiveDP(n,k-1,dp):0))%mod;
    }
};
