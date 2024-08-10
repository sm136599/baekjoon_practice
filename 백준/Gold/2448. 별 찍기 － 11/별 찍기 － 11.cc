#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

void drawStar(vector<string>& board, int n, int x, int y,int target) {
    if (n == 3) {
        if (y == target) {
            board[0][x] = '*';
            board[1][x - 1] = '*';
            board[1][x + 1] = '*';
            board[2][x - 2] = '*';
            board[2][x - 1] = '*';
            board[2][x] = '*';
            board[2][x + 1] = '*';
            board[2][x + 2] = '*';
        }
    }
    else {
        int newSize = n / 2;
        drawStar(board, newSize, x, y, target);
        drawStar(board, newSize, x - newSize, y + newSize, target);
        drawStar(board, newSize, x + newSize, y + newSize, target);
    }
}

int main() {
    sws;
    int n; cin >> n;

    for (int target = 0; target < n; target += 3) {
        vector<string> board(3, string(2 * n - 1, ' '));


        drawStar(board, n, n - 1, 0, target);


        for (const string& row : board) {
            cout << row << '\n';
        }
    }

    return 0;
}