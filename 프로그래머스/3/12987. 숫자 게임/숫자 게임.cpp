#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int aIdx = 0, bIdx = 0;
    while (aIdx < N && bIdx < N) {
        if (A[aIdx] < B[bIdx]) {
            answer++;
            aIdx++;
            bIdx++;
        }
        else {
            bIdx++;
        }
    }
    
    
    return answer;
}