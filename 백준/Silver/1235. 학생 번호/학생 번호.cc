#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	vector<string> no(N);
	for (int i = 0; i < N; i++) cin >> no[i];
	int len = no[0].size();
	for (int k = 1; k <= len; k++) {
		bool flag = true;
		for (int i = 0; i < N; i++) {
			string compare = no[i].substr(len - k, k);
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (compare == no[j].substr(len - k, k))
					flag = false;
			}
		}
		if (flag) {
			cout << k << '\n';
			break;
		}
	}

	return 0;
}