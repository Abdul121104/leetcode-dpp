class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(),n= grid[0].size();
        vector<int> rowCount1(m, 0),rowCount0(m, 0);
        vector<int> colCount1(n, 0),colCount0(n, 0);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    rowCount1[row]++;
                    colCount1[col]++;
                }
                else{
                    rowCount0[row]++;
                    colCount0[col]++;
                }
            }
        }
        vector<vector<int>> diff(m,vector<int>(n));
        for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
                diff[row][col]=rowCount1[row]+colCount1[col]-rowCount0[row]-colCount0[col];
            }
        }
        return diff;
    }
};
