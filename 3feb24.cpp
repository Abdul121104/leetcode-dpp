class Solution {
public:
    int dp[501];
    int f(int i, vector<int>& arr, int k ,vector<int> &dp){
        int n = arr.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int length = 0;
        int maxi = INT_MIN, maxLength = INT_MIN;
        for(int j = i; j < min(i + k, n); ++j){
            length++;
            maxi = max(maxi, arr[j]);
            int sum = length * maxi + f(j + 1, arr, k ,dp);
            maxLength = max(maxLength, sum);
        }
        return dp[i] = maxLength;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k ) {
        int n = arr.size();
        vector<int> dp ( n , -1);
        return f(0, arr, k ,dp);
    }
}; 
