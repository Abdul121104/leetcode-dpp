class Solution {
public:
    #define MOD 1000000007
    int dp[31][1001];
    int solve(int d, int f, int target){
        if(d==0 && target==0) return 1;
        if(d<=0 || target<=0) return 0;
        if(dp[d][target] != -1) return dp[d][target];
        int sum=0;
        for(int i=1;i<=f;i++)sum = (sum % MOD + solve(d-1,f,target-i)%MOD)%MOD;
        return dp[d][target] = sum;;
    }
    int numRollsToTarget(int d, int f, int target) {
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        memset(dp,-1,sizeof(dp));
        return solve(d,f,target);
    }
};
