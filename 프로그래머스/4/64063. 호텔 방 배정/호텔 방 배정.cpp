#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    int n = room_number.size();
    vector<long long> answer(n);
    unordered_map<long long, long long> m;
    for (int i = 0; i < n; i++) {
        long long wish = room_number[i];
        if (m.find(wish) == m.end()) {
            m[wish] = wish + 1;
            answer[i] = wish;
        }
        else {
            vector<long long> update;
            long long decided = wish;
            while (true) {
                if (m.find(decided) == m.end()) {
                    m[decided] = decided + 1;
                    answer[i] = decided;
                    break;
                }
                else {
                    update.push_back(decided);
                    decided = m[decided];
                }
            }
            for(auto u : update) {
                m[u] = decided;
            }
        }
    }
    return answer;
}