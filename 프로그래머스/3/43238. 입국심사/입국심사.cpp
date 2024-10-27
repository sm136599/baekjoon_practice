#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 0;
    // 이분 탐색?
    
    ll s = 1, e = 1000000000000000000;
    while (s <= e) {
        ll m = (s+e) / 2;
        ll can = 0;
        for (ll time : times) {
            can += m / time;
        }
        if (n > can) {
            s = m + 1;
        }
        else {
            e = m - 1;
            answer = m;
        }
    }
    
    
    return answer;
}