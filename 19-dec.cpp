class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size(),cols = img[0].size();
        vector<vector<int>> result(rows,vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i){for (int j = 0; j < cols; ++j){int t=0,c=0;for (int x = max(0,i-1);x<min(rows,i+2);++x){for (int y=max(0,j-1); y <min(cols,j+2);++y) {t+= img[x][y];c+=1;}}result[i][j] = t/c;}}
        return result;
    }
};
