#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    vector<int> nums;
    vector<string> ops;
    nums.push_back(stoi(arr[0]));
    for (int i = 2; i < arr.size(); i += 2) {
        nums.push_back(stoi(arr[i]));
        ops.push_back(arr[i-1]);
    }
    int n = nums.size();
    vector<vector<int>> maxDP(n, vector<int>(n, -1000000));
    vector<vector<int>> minDP(n, vector<int>(n, 1000000));
    for (int i = 0; i < n; i++) {
        maxDP[i][i] = nums[i];
        minDP[i][i] = nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (ops[k] == "+") {
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] + maxDP[k+1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] + minDP[k+1][j]);
                } else {
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] - minDP[k+1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] - maxDP[k+1][j]);
                }
            }
        }
    }
    return maxDP[0][n-1];
}