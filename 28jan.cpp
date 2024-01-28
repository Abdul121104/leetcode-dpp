class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 1; j < cols; j++)
                matrix[i][j] += matrix[i][j - 1];

        for (int startCol = 0; startCol < cols; startCol++){
            for (int endCol = startCol; endCol < cols; endCol++){
                map<int, int> sumCount;
                sumCount[0] = 1;
                int currentSum = 0;
                for (int row = 0; row < rows; row++) {
                    int subtractValue = 0;
                    if (startCol > 0) {
                        subtractValue = matrix[row][startCol - 1];
                    }
                    currentSum += matrix[row][endCol] - subtractValue;
                    result += sumCount[currentSum - target];
                    sumCount[currentSum]++;
                }
            }
        }

        return result;
    }
};
