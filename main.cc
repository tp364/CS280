#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8;
int board[N][N];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
}

bool knightTour(int x, int y, int move) {
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

int main() {
    for (int i = 0; i < N; ++i)
        fill(board[i], board[i] + N, 0);

    board[0][0] = 1;
    if (knightTour(0, 0, 2)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << setw(2) << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
