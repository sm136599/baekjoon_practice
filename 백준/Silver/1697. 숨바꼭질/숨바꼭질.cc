#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { false, };

bool valid(int n) {
	return (!(n < 0 || n > 100000 || visited[n]));
}

int main(void) {
	int N, K;
	cin >> N >> K;
	queue<pair<int,int>> q;
	q.push(make_pair(N,0));
	visited[N] = true;
	while (!q.empty()) {
		if (q.front().first == K) break;
		int minus = q.front().first - 1;
		int plus = q.front().first + 1;
		int mul = q.front().first * 2;
		if (valid(minus)) {
			visited[minus] = true;
			q.push(make_pair(minus, q.front().second + 1));
		}
		if (valid(plus)) {
			visited[plus] = true;
			q.push(make_pair(plus, q.front().second + 1));
		}
		if (valid(mul)) {
			visited[mul] = true;
			q.push(make_pair(mul, q.front().second + 1));
		}
		q.pop();
	}
	cout << q.front().second << "\n";
	return 0;
}