public class Main {
    static final int N = 8;
    static int[][] board = new int[N][N];
    static int[] dx = {2, 1, -1, -2, -2, -1, 1, 2};
    static int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};

    static boolean isValid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
    }

    static boolean knightTour(int x, int y, int move) {
        if (move == N * N + 1)
            return true;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                board[nx][ny] = move;
                if (knightTour(nx, ny, move + 1))
                    return true;
                board[nx][ny] = 0;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        board[0][0] = 1;
        if (knightTour(0, 0, 2)) {
            for (int[] row : board) {
                for (int cell : row)
                    System.out.printf("%2d ", cell);
                System.out.println();
            }
        } else {
            System.out.println("No solution found.");
        }
    }
}
