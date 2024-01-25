class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(j>0 and j<m-1){  
                   matrix[i][j]+=min(matrix[i+1][j],min(matrix[i+1][j-1],matrix[i+1][j+1]));
                }
                else if(j==0){
                    matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j+1]);
                }
                else matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j-1]);
            }
        }
        ans=*min_element(matrix[0].begin(),matrix[0].end());
        return ans;
    }
};