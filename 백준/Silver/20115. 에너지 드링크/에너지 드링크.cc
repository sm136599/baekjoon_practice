#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	vector<double> nums(N);
	for (int i = 0; i < N; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	double sum = 0;
	for (int i = 0; i < N - 1; i++) sum += nums[i];
	sum /= 2;
	sum += nums[N - 1];
	cout << sum;
	return 0;
}