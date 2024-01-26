class Solution {
public:
    long long mod = 1e9+7;
    int findPath(int m, int n, int moves, int startRow, int startCol,vector<vector<vector<long long>>>& dp) {
        if ((startRow<0 || startCol<0 || startRow >= m || startCol >= n) && moves>=0) {
            return 1;
        }
        if (moves<0) return 0;
        if (dp[moves][startRow][startCol] != -1) return dp[moves][startRow][startCol];
        long long up = findPath(m,n,moves-1,startRow-1,startCol,dp);
        long long right = findPath(m,n,moves-1,startRow,startCol+1,dp);
        long long down = findPath(m,n,moves-1,startRow+1,startCol,dp);
        long long left = findPath(m,n,moves-1,startRow,startCol-1,dp);
        return dp[moves][startRow][startCol] = (up+right+down+left)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp(maxMove+1,vector<vector<long long>>(m,vector<long long>(n,-1)));
        return findPath(m,n,maxMove,startRow,startColumn,dp);
    }
};
