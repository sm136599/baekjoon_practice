#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
/*
입력받은 이름들을 해시 테이블(map)을 이용해 숫자로 바꾼다.
만들어진 친구관계(그래프)를 통해 연결된 친구가 몇 명 있는지 수를 센다.
*/

int count_friends(int f1, int f2, vector<int>& group, vector<int>& group_count, int& group_idx) {
	if (group[f1] == -1 && group[f2] == -1) {
		group[f1] = group[f2] = group_idx++;
		group_count[group[f1]] = 2;
		return 2;
	}
	else if (group[f1] == -1) {
		group[f1] = group[f2];
		group_count[group[f1]]++;
		return group_count[group[f1]];
	}
	else if (group[f2] == -1) {
		group[f2] = group[f1];
		group_count[group[f1]]++;
		return group_count[group[f1]];
	}
	else if (group[f1] == group[f2]) {
		return group_count[group[f1]];
	}
	else {
		int check_group = group[f1];
		for (int i = 0; i < group.size(); i++) {
			if (group[i] == -1) break;
			if (group[i] == check_group) {
				group[i] = group[f2];
				group_count[group[f2]]++;
			}
		}
		return group_count[group[f2]];
	}
}

int get_index(unordered_map<string, int>& hash, int& index, string name) {
	if (hash.find(name) == hash.end()) {
		hash[name] = index++;
	}
	return hash[name];
}

int main(void) {
	sws;
	int t; cin >> t;
	while (t--) {
		int f; cin >> f;
		unordered_map<string, int> hash;
		vector<int> group(2 * f, -1);
		vector<int> group_count(f, 0);
		int index = 0;
		int group_idx = 0;
		for (int i = 0; i < f; i++) {
			string f1, f2; cin >> f1 >> f2;
			int f1_index = get_index(hash, index, f1);
			int f2_index = get_index(hash, index, f2);
			cout << count_friends(f1_index, f2_index, group, group_count, group_idx) << '\n';
		}
	}

	return 0;
}