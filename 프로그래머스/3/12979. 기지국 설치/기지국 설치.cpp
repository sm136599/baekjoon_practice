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
    int start = 1, end;
    for (int i = 0; i < stations.size(); i++) {
        end = stations[i] - w - 1;
        answer += getCount(start, end, w);
        start = stations[i] + w + 1;
    }
    answer += getCount(start, n, w);
    return answer;
}
