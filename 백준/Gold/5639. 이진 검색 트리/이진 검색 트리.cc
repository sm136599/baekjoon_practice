#include "bits/stdc++.h"

using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX 10000000

struct Node {
	Node* left;
	Node* right;
	Node* parent;
	int num;
	Node(int num) : num(num) {
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

class BinaryTree {
	Node* seed;
protected:
	bool isLeaf(Node* node) {
		return (node->left == NULL && node->right == NULL);
	}
	void build(vector<int>& input, Node* cur) {
		Node* temp;
		for (int i = 0; i < input.size(); i++) {
			if (cur->num > input[i]) {
				temp = new Node(input[i]);
				cur->left = temp;
				temp->parent = cur;
				cur = temp;
			}
			else {
				while (true) {
					if (cur->num > input[i]) break;
					cur = cur->parent;
				}
				cur = cur->left;
				while (true) {
					if (cur->right == NULL) break;
					cur = cur->right;
				}
				temp = new Node(input[i]);
				cur->right = temp;
				temp->parent = cur;
				cur = temp;
			}
		}
	}
	void printTree(Node* cur) {
		if (cur == NULL) return;
		printTree(cur->left);
		printTree(cur->right);
		cout << cur->num << '\n';
	}
public:
	BinaryTree(vector<int>& input) {
		seed = new Node(MAX);
		build(input, seed);
	}
	void print() {
		printTree(seed->left);
	}
};

int main(void) {
	sws;
	vector<int> input;
	int a;
	while (true) {
		cin >> a;
		if (cin.eof()) break;
		input.push_back(a);
	}
	BinaryTree bt(input);
	bt.print();

	return 0;
}