#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there's a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // All queens are placed successfully, print the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] == 1 ? "Q" : ".");
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool result = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            result = solveNQueens(board, row + 1, N) || result;
            board[row][col] = 0; // Backtrack
        }
    }
    return result;
}

void nQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueens(board, 0, N)) {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    nQueens(N);

    return 0;
}
