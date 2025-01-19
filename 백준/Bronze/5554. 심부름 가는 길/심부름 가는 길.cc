#include <iostream>
using namespace std;
int main(void) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int a; cin >> a;
        sum += a;
    }
    cout << sum / 60 << '\n' << sum % 60;
}