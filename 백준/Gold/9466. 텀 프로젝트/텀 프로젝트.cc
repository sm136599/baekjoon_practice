#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

vector<int> choice;
vector<int> visited;
vector<bool> hasTeam;
vector<bool> noTeam;

void dfs(int cur) {
	if (hasTeam[cur]) return;
	if (noTeam[cur]) return;
	if (visited[cur] == 1) {
		hasTeam[cur] = true;
	}
	else if (visited[cur] == 2) {
		return;
	}
	visited[cur]++;
	dfs(choice[cur]);
	if (!hasTeam[cur]) noTeam[cur] = true;
	visited[cur]--;
}

int main(void) {
	sws;
	int T; cin >> T;
	string answers = "";
	while (T--) {
		int n; cin >> n;
		choice.clear();
		choice.resize(n + 1);
		visited.clear();
		visited.resize(n + 1, 0);
		hasTeam.clear();
		hasTeam.resize(n + 1, false);
		noTeam.clear();
		noTeam.resize(n + 1, false);

		for (int i = 1; i <= n; i++) {
			cin >> choice[i];
			if (i == choice[i]) hasTeam[i] = true;
		}
		
		for (int i = 1; i <= n; i++) {
			if (hasTeam[i]) continue;
			dfs(i);
			if (!hasTeam[i]) noTeam[i] = true;
		}

		int answer = 0;
		for (int i = 1; i <= n; i++) if (!hasTeam[i]) answer++;
		answers.append(to_string(answer) + "\n");
	}
	cout << answers;

	return 0;
}