// TicTacToeAI.cpp
#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

// Function to display the board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        cout << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if any moves are left
bool movesLeft() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

// Function to check for a winner
int evaluate() {
    // Check rows
    for (int i = 0; i < SIZE; i++)
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            if (board[i][0] == 'O') return +10;
            else if (board[i][0] == 'X') return -10;
        }

    // Check columns
    for (int j = 0; j < SIZE; j++)
        if (board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            if (board[0][j] == 'O') return +10;
            else if (board[0][j] == 'X') return -10;
        }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') return +10;
        else if (board[0][0] == 'X') return -10;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == 'O') return +10;
        else if (board[0][2] == 'X') return -10;
    }

    return 0; // No winner
}

// Minimax algorithm
int minimax(bool isAI) {
    int score = evaluate();

    if (score == 10 || score == -10)
        return score;

    if (!movesLeft())
        return 0;

    if (isAI) {
        int best = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = max(best, minimax(false));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = min(best, minimax(true));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

// Find the best move for AI
pair<int, int> findBestMove() {
    int bestVal = -1000;
    pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveVal = minimax(false);
                board[i][j] = ' ';

                if (moveVal > bestVal) {
                    bestMove = { i, j };
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

// Main gameplay function
void playGame() {
    int row, col;
    initializeBoard();
    printBoard();

    while (movesLeft() && evaluate() == 0) {
        // Player's move
        cout << "Enter your move (row and column: 0 1 2): ";
        cin >> row >> col;

        if (board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = 'X';
        printBoard();

        if (evaluate() == -10) {
            cout << "You win!" << endl;
            return;
        }

        if (!movesLeft()) break;

        // AI's move
        cout << "AI is making a move...\n";
        pair<int, int> aiMove = findBestMove();
        board[aiMove.first][aiMove.second] = 'O';
        printBoard();

        if (evaluate() == 10) {
            cout << "AI wins!" << endl;
            return;
        }
    }

    cout << "It's a draw!" << endl;
}

int main() {
    cout << "Welcome to Tic Tac Toe vs AI!" << endl;
    playGame();
    return 0;
}
