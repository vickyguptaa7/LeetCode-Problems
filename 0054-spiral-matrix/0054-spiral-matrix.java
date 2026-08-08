class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        List<Integer> arr = new ArrayList<>();
        int top = 0, left = 0, bottom = n - 1, right = m - 1;
        int total = n * m;
        while (total > 0) {
            for (int i = left; i <= right && total > 0; i++) {
                System.out.println(matrix[top][i]);
                arr.add(matrix[top][i]);
                total--;
            }
            top++;
            for (int i = top; i <= bottom && total > 0; i++) {
                System.out.println(matrix[i][right]);
                arr.add(matrix[i][right]);
                total--;
            }
            right--;
            for (int i = right; i >= left && total > 0; i--) {
                System.out.println(matrix[bottom][i]);
                arr.add(matrix[bottom][i]);
                total--;
            }
            bottom--;
            for (int i = bottom; i >= top && total > 0; i--) {
                System.out.println(matrix[i][left]);
                arr.add(matrix[i][left]);
                total--;
            }
            left++;
        }
        return arr;
    }
}