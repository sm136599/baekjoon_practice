#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;
vector<bool> visited;
int cnt = 0;
int N;

bool isOk(vector<int>& stack, int N, int l, int m) {
  for (int mm = m+1; mm < N*2; mm++) {
    int ll = l + m - mm;
    if (0 <= ll && ll < N) {
      if (stack[ll] == mm || stack[ll] == m*2 - mm) {
        return false;
      }
    }
  }
  return true;
}

void bt(int i, int j) {
  if (i == N - 1) {
      cnt++;
      return;
  }
  for (int k = 0; k < N; k++) {
    if (!visited[k]) {
      if (stack[i] == k - 1 || stack[i] == k + 1) {
        continue;
      }
      if (isOk(stack, N, i + 1, k)) {
        stack.push_back(k);
        visited[k] = true;
        bt(i + 1, k);
        stack.pop_back();
        visited[k] = false;
      }
    }
  }
}
int main() {
    
    cin >> N;
    
	visited = vector<bool>(N, false);
    for (int i = 0; i < N; i++) {
        stack.push_back(i);
        visited[i] = true;
        bt(0, i);
        stack.pop_back();
        visited[i] = false;
    }

    cout << cnt << endl;
    return 0;
}