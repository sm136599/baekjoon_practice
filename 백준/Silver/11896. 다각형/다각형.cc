#include <iostream>
using namespace std;
int main(void) {
    long long a, b; cin >> a >> b; 
    a = (a < 3)?3:a;
    b = (b < 3)?3:b;
    cout << (((b/2) - ((a+1)/2) + 1)*((b/2) + ((a+1)/2)));
    return 0;
}