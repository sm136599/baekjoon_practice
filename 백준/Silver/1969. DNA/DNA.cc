#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

#define A 0
#define C 1
#define G 2
#define T 3

int main(void) {
	sws;
	int N, M; cin >> N >> M;
	vector<vector<unsigned short>> dnas(4, vector<unsigned short>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			switch (c)
			{
			case 'A':
				dnas[A][j]++; break;
			case 'T':
				dnas[T][j]++; break;
			case 'G':
				dnas[G][j]++; break;
			case 'C':
				dnas[C][j]++; break;
			default:
				break;
			}
		}
	}
	int hamming_distance = 0;
	for (int j = 0; j < M; j++) {
		char max_char;
		unsigned short count = 0;
		for (int i = 0; i < 4; i++) {
			if (count < dnas[i][j]) {
				count = dnas[i][j];
				max_char = (i == 0) ? 'A' : (i == 1) ? 'C' : (i == 2) ? 'G' : (i == 3) ? 'T' : ' ';
			}
		}
		cout << max_char;
		hamming_distance += N - count;
	}
	cout << '\n' << hamming_distance;
	return 0;
}