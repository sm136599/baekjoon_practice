#include <iostream>
#include <vector>
using namespace std;
int getCount(int start, int end, int w) {
    int size = 2*w + 1;
    int diff = (end - start + 1);
    if (start > end) return 0;
    if (diff % size) {
        return (diff / size) + 1;
    }
    else {
        return diff / size;
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int len = stations.size();
    int start = 0;
    int end = stations[0] - 1 - w - 1;
    answer += getCount(start, end, w);
    start = stations[0] - 1 + w + 1;
    for (int i = 1; i < len; i++) {
        end = stations[i] - 1 - w - 1;
        answer += getCount(start, end, w);
        start = stations[i] - 1 + w + 1;
    }
    answer += getCount(start, n-1, w);
    return answer;
}