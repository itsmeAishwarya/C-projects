#include <iostream>
using namespace std;

char board[3][3]; // 3x3 grid
char currentPlayer = 'X';

// function to print the board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// function to check winner
bool checkWin() {
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
    }
    // cols
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
            return true;
    }
    // diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// switch player
void changePlayer() {
    if (currentPlayer == 'X') currentPlayer = 'O';
    else currentPlayer = 'X';
}

int main() {
    // fill board with spaces first
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    cout << "Tic Tac Toe Game!\n";
    printBoard();

    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move, try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        printBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        changePlayer();
    }

    return 0;
}
