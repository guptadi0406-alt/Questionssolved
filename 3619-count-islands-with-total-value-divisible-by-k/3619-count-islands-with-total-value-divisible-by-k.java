class Solution {

    public static int dfs(int i, int j, int[][] grid, int[] dr, int[] dc, boolean[][] visited) {
        visited[i][j] = true;
        int sum = grid[i][j];

        for (int d = 0; d < 4; d++) {
            int nr = i + dr[d];
            int nc = j + dc[d];

            if (nr >= 0 && nc >= 0 &&
                nr < grid.length && nc < grid[0].length &&
                grid[nr][nc] != 0 && !visited[nr][nc]) {

                sum += dfs(nr, nc, grid, dr, dc, visited);
            }
        }
        return sum;
    }

    public int countIslands(int[][] grid, int k) {

       

        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, -1, 0, 1};

        int count = 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {

                if (grid[i][j] != 0 && !visited[i][j]) {
                    int sum = dfs(i, j, grid, dr, dc, visited);
                    if (sum % k == 0 && sum!=0) count++;
                }
            }
        }
        return count;
    }
}