#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;


int solution(vector<int> a) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < a.size(); i++) {
        pq.push(make_pair(a[i], i));
    }
    int leftMin, rightMin;
    leftMin = rightMin = pq.top().second;
    pq.pop();
    answer++;
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (cur < leftMin) {
            leftMin = cur;
            answer++;
        }
        if (cur > rightMin) {
            rightMin = cur;
            answer++;
        }
    }
    
    return answer;       
}