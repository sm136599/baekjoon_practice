#include <string>
#include <vector>
#include <iostream>

#define min(a, b) ((a) < (b))? (a) : (b)

using namespace std;
bool first[]{true, false, true};
bool second[]{true, true, false};


int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 30;
    int n = beginning.size();
    int m = beginning[0].size();
    
    for (int k = 0; k < 3; k++) {
        int ans1 = 0, ans2 = 0;
        vector<vector<int>> b1 = beginning;
        vector<vector<int>> b2 = beginning;
        for (int i = 0; i < n; i++) {
            if ((b1[i][0] != target[i][0]) == first[k]) {
                for (int j = 0; j < m; j++) b1[i][j] ^= 1;
                ans1++;
            }
        }
        for (int j = 0; j < m; j++) {
            if ((b1[0][j] != target[0][j]) == second[k]) {
                for (int i = 0; i < n; i++) b1[i][j] ^= 1;
                ans1++;
            }
        }
        
        for (int j = 0; j < m; j++) {
            if ((b2[0][j] != target[0][j]) == second[k]) {
                for (int i = 0; i < n; i++) b2[i][j] ^= 1;
                ans2++;
            }
        }
        for (int i = 0; i < n; i++) {
            if ((b2[i][0] != target[i][0]) == first[k]) {
                for (int j = 0; j < m; j++) b2[i][j] ^= 1;
                ans2++;
            }
        }
        bool isValid1 = true, isValid2 = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b1[i][j] != target[i][j]) {
                    isValid1 = false;
                }
                if (b2[i][j] != target[i][j]) {
                    isValid2 = false;
                }
            }
        }
        
        if (isValid1) answer = min(answer, ans1);
        if (isValid2) answer = min(answer, ans2);
    }
    
    
    
    if (answer != 30)
        return answer;
    else 
        return -1;
}