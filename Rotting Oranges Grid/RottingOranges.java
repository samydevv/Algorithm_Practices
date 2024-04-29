import java.util.*;

class Pair {
    public Integer i;
    public Integer j;

    public Pair(Integer i, Integer j) {
        this.i = i;
        this.j = j;
    }

}

public class RottingOranges {
    public static void main(String[] args) {
        int m = 3, n = 4;
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 0;
            }
        }
        grid[0][1] = 1;
        grid[0][3] = 1;

        grid[1][1] = 1;
        grid[1][2] = 2;
        grid[1][3] = 2;

        grid[2][3] = 1;


        System.out.println(ROG(grid));
        printGrid(grid);
    }

    public static int ROG(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        int infected = 2, fresh = 1, num_fresh = 0, num_minute = 0;
        Queue<Pair> queue = new ArrayDeque<>();
        List<Pair> direction = Arrays.asList(new Pair(0, 1), new Pair(1, 0), new Pair(0, -1), new Pair(-1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == infected)
                    queue.add(new Pair(i, j));
                else if (grid[i][j] == fresh)
                    num_fresh += 1;
            }
        }

        if (num_fresh == 0)
            return -1;

        while (!queue.isEmpty()) {
            num_minute += 1;
            Pair p = queue.poll();
            for (Pair d : direction) {
                int i_new = p.i + d.i, j_new = p.j + d.j;
                if (0 <= i_new && i_new < m && 0 <= j_new && j_new < n && grid[i_new][j_new] == fresh) {
                    num_fresh -= 1;
                    grid[i_new][j_new] = infected;
                    queue.add(new Pair(i_new, j_new));

                }
            }
        }

        if (num_fresh > 0)
            return -1;
        else
            return num_minute -1;

    }

    public static void printGrid(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println(" ");
        }
    }
}
