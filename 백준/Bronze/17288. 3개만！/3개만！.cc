#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	string in; cin >> in;
	in += '\0';
	int answer = 0;
	int count = 1;
	char prev = '\0';
	for (char c : in) {
		if (c - prev == 1) {
			count++;
		}
		else {
			if (count == 3) {
				answer++;
			}
			count = 1;
		}
		prev = c;
	}
	cout << answer << endl;
	return 0;
}