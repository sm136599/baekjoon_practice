#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> count(n+1);
    count[0] = 1;
    for (int m : money) {
        for (int i = m; i <= n; i++) {
            count[i] += count[i-m];
        }
    }
    return count[n];
}