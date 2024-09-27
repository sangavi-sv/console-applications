#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

void printBoard() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

void takeTurn(string player) {
    cout << player << "'s turn." << endl;
    cout << "Choose a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1;
    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "Invalid input or position already taken. Choose a different position: ";
        cin >> position;
        position -= 1;
    }
    board[position] = player;
    printBoard();
}

string checkGameOver() {
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != "-") ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != "-") ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != "-") ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != "-") ||
        (board[0] == board[4] && board[4] == board[8] && board[0] != "-") ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) {
        return "win";
    }

    else if (count(board.begin(), board.end(), "-") == 0) {
        return "tie";
    }
 
    else {
        return "play";
    }
}

int main() {
    printBoard();
    string currentPlayer = "X";
    bool gameOver = false;
    while (!gameOver) {
        takeTurn(currentPlayer);
        string gameResult = checkGameOver();
        if (gameResult == "win") {
            cout << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (gameResult == "tie") {
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            currentPlayer = currentPlayer == "X" ? "O" : "X";
        }
    }
    return 0;
}
