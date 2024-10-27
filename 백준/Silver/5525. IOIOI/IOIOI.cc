#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N, M; cin >> N >> M;
	string inp; cin >> inp;
	string target = "I";
	for (int i = 0; i < N; i++) target += "OI";
	int answer = 0;
	for (int i = 0; i <= M - target.size(); i++) {
		bool isValid = true;
		for (int j = 0; j < target.size(); j++) {
			if (inp[i + j] != target[j]) {
				isValid = false;
				break;
			}
		}
		if (isValid) answer++;
	}

	cout << answer;
	return 0;
}