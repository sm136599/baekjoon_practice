#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<int>>& dist, int& n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << dist[i][j] << '\t'; 
        cout << endl;
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    const int inf = 20000000;
    vector<vector<int>> dist(n+1, vector<int>(n+1, inf));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < fares.size(); i++) {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    //print(dist, n);
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    //print(dist, n);
    
    answer = dist[s][a] + dist[s][b];
    for (int i = 1; i <= n; i++) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}