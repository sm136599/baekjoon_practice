#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

void print0() {
	cout << "      ";
}
void print1() {
	cout << "  *   ";
}
void print2() {
	cout << " * *  ";
}
void print5() {
	cout << "***** ";
}



vector<string> print(int n) {
	if (n == 3) {
		return { "  *   ", " * *  ", "***** " };
	}
	else {
		vector<string> v = print(n / 2);
		int temp = v[0].size() / 2;
		string blank = "";
		for (int i = 0; i < temp; i++) blank += " ";
		vector<string> ret;
		for (int i = 0; i < v.size(); i++) {
			ret.push_back(blank + v[i] + blank);
		}
		for (int i = 0; i < v.size(); i++) {
			ret.push_back(v[i] + v[i]);
		}
		return ret;
	}
}

int main(void) {
	sws;

	int N; cin >> N;
	vector<string> answer = print(N);
	for (auto s : answer) cout << s << endl;

	return 0;
}