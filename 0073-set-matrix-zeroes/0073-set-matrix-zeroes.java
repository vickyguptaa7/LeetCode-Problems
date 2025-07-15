class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        boolean isFirstRowZero = false;
        boolean isFirstColZero = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                isFirstRowZero = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) {
                isFirstColZero = true;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isFirstRowZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
        if (isFirstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[0][i] = 0;
            }
        }
    }
}