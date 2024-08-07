#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	vector<int> liquid(N);
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}

	int start = 0, end = N - 1;
	int answer = abs(liquid[start] + liquid[end]);
	int answerS = 0, answerE = N - 1;
	while (start < end) {
		int temp = liquid[start] + liquid[end];
		if (abs(temp) <= answer) {
			answer = abs(temp);
			answerS = start;
			answerE = end;
		}
		if (temp > 0) {
			end--;
		}
		else {
			start++; 
		}
	}
	cout << liquid[answerS] << " " << liquid[answerE] << endl;

	return 0;
}