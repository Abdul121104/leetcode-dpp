class Solution {
public:
    vector<int> dir = {1 , 0 , -1};
    bool isValid(int i , int j , vector<vector<int>> &grid){
        int m = grid.size() , n = grid[0].size();
        if( i >= 0 && i < m && j >= 0 && j < n ) return true;
        return false;
    }
    int f(int i , int j1 , int j2 , vector<vector<int>> &grid , vector<vector<vector<int>>> &dp){
        if(i == grid.size()) return 0;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int ans = INT_MIN;
        for(int p=0 ; p<3 ; p++){
            int newi = i + 1 , newj1 = j1 + dir[p]; 
            for(int k=0 ; k<3 ; k++){
                int newj2 = j2 + dir[k]; 
                int cur; 
                if(j1 == j2){
                    cur = grid[i][j1];
                }
                else{
                    cur = grid[i][j1] + grid[i][j2];
                }
                if(isValid(newi , newj1 , grid) && isValid(newi , newj2 , grid)) 
                    cur += f(newi , newj1 , newj2 , grid , dp);
                ans = max(ans , cur);
            }
        }
        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int> (n , -1)));
        return f(0,0,n-1,grid,dp);
    }
};
