class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += Math.min(matrix[i-1][Math.max(j-1, 0)], 
                                         Math.min(matrix[i-1][j], 
                                                  matrix[i-1][Math.min(j+1, cols-1)]));
            }
        }

        int minSum = Integer.MAX_VALUE;
        for (int num : matrix[rows-1]) {
            minSum = Math.min(minSum, num);
        }

        return minSum;
    }
}