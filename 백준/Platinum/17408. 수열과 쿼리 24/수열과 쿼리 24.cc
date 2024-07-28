#include "bits/stdc++.h"
using namespace std;

class SegmentTree {
	vector<pair<int, int>> tree;
	vector<int> original;
	int size;
public:
	SegmentTree(vector<int>& input) {
		original = input;
		size = input.size();
		tree = vector<pair<int, int>>(input.size() * 4);
		generate(1, 0, size - 1);
	}
	pair<int, int> generate(int idx, int start, int end) {
		if (start == end) return tree[idx] = make_pair(start, end);
		int mid = (start + end) / 2;
		return tree[idx] = getFS(generate(idx * 2, start, mid), generate(idx * 2 + 1, mid + 1, end));
	}

	void update(int index, int num) {
		original[index] = num;
		updateTree(1, 0, size - 1, index, num);
	}

	pair<int, int> updateTree(int idx, int start, int end, int target, int changeN) {
		if (target < start || end < target) return tree[idx];
		if (start == end) return tree[idx];
		int mid = (start + end) / 2;
		return tree[idx] = getFS(updateTree(idx * 2, start, mid, target, changeN),
							updateTree(idx * 2 + 1, mid + 1, end, target, changeN));
	}

	int query(int left, int right) {
		pair<int, int> result = queryTree(1, 0, size - 1, left, right);
		return original[result.first] + original[result.second];
	}

	pair<int, int> queryTree(int idx, int start, int end, int left , int right) {
		if (left > end || right < start) return make_pair(-1, -1);
		if (left <= start && right >= end) return tree[idx];
		int mid = (start + end) / 2;
		pair<int, int> a = queryTree(idx * 2, start, mid, left, right);
		pair<int, int> b = queryTree(idx * 2 + 1, mid + 1, end, left, right);
		if (a.first == -1) return b;
		else if (b.first == -1) return a;
		else return getFS(a, b);
	}

	pair<int, int> getFS(const pair<int, int>& a, const pair<int, int>& b) {
		priority_queue<pair<int, int>> pq; 
		pq.push(make_pair(original[a.first], a.first)); 
		if (a.first != a.second) pq.push(make_pair(original[a.second], a.second)); 
		pq.push(make_pair(original[b.first], b.first)); 
		if (b.first != b.second) pq.push(make_pair(original[b.second], b.second)); 
		int max1 = pq.top().second; pq.pop();
		int max2 = pq.top().second; pq.pop();
		return make_pair(max1, max2);
	}

	void print() {
		for (int i = 0; i < original.size(); i++) {
			cout << original[i] << " ";
		}
		cout << '\n';
		int h = 1;
		while (pow(2, h) <= tree.size()) {
			for (int j = pow(2, h - 1); j < pow(2, h); j++) {
				cout << "(" << tree[j].first << "," << tree[j].second << ") ";
			}
			cout << "\n";
			h++;
		}
	}
};

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	int N, M; cin >> N;
	
	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	SegmentTree sTree(input);

	//sTree.print();
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			sTree.update(b - 1, c);
			//sTree.print();
		}
		else {
			cout << sTree.query(b - 1, c - 1) << '\n';
		}
	}
	
	return 0;
}