#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void updateBoard(vector<vector<int>>& board, int i0, int i1, int j0, int j1, int value) {
    board[i0][j0] += value;
    board[i1+1][j1+1] += value;
    board[i0][j1+1] -= value;
    board[i1+1][j0] -= value;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    vector<vector<int>> newBoard(n+1, vector<int>(m+1));
    
    for (auto s : skill) {
        if (s[0] == 1) {
            updateBoard(newBoard, s[1], s[3], s[2], s[4], -s[5]);
        }
        else {
            updateBoard(newBoard, s[1], s[3], s[2], s[4], s[5]);
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            newBoard[i][j] = newBoard[i][j-1] + newBoard[i][j];
        }
    }
    for (int j = 0; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            newBoard[i][j] = newBoard[i-1][j] + newBoard[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + newBoard[i][j] > 0) answer++;
        }
    }
    return answer;
}