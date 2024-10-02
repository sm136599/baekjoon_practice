#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws; int N, M; cin >> N >> M;
	int price1 = 1000, price6 = 1000;
	for (int i = 0; i < M; i++) {int p1, p6; cin >> p6 >> p1;price1 = min(price1, p1);price6 = min(price6, p6);}
	cout << min(N*price1, min((((N - 1) / 6 + 1) * price6), ((N / 6) * price6 + (N % 6) * price1))) << endl;
	return 0;
}