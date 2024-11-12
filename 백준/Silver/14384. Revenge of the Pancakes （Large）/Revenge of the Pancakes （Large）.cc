#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int answer = 0;
		string str; cin >> str;
		str += "+";
		char prev = str[0];
		for (int i = 1; i < str.size(); i++) {
			if (prev != str[i]) answer++;
			prev = str[i];
		}
		cout << "Case #" << t << ": " << answer << '\n';
	}
	return 0;
}