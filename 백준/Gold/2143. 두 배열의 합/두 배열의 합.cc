#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
int main(void) {
	sws;
	int T; cin >> T;
	vector<int> A, B;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		A.push_back(a);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int b; cin >> b;
		B.push_back(b);
	}
	unordered_map<int, int> possible_sum_count_A, possible_sum_count_B;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			possible_sum_count_A[sum]++;
		}
	}

	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			possible_sum_count_B[sum]++;
		}
	}

	long long answer = 0;
	for (auto& p : possible_sum_count_A) {
		int target_sum = T - p.first;
		answer += (long long)p.second * (long long)possible_sum_count_B[target_sum];
	}

	cout << answer;
	return 0;
}