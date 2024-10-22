#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
#define EPS 1e-6

static int comp(double a, double b) {
	if (abs(a - b) < EPS) return 0;
	return (a < b) ? -1 : 1;
}

int main(void) {
	sws;
	int T; cin >> T;
	while (T--) {
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) cout << "-1\n";
			else cout << "0\n";
			continue;
		}
		if (comp(dist + r1, r2) == -1 ||
			comp(dist + r2, r1) == -1) {
			cout << "0\n";
			continue;
		}
		if (comp(dist + r1, r2) == 0 ||
			comp(dist + r2, r1) == 0) {
			cout << "1\n";
			continue;
		}

		switch (comp(dist, r1 + r2)) 
		{
		case -1:
			cout << "2\n";
			break;
		case 0:
			cout << "1\n";
			break;
		case 1:
			cout << "0\n";
			break;
		default:
			break;
		}

	}

	return 0;
}