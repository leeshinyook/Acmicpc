#include <iostream>
using namespace std;
int NumLength(long long num) {
    int length = 0;
    while(num) {
        num /= 10;
        length++;
    }
    return length;
}
int main() {
    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    for(int i = 0; i < NumLength(b); i++) {
        a *= 10;
    }
    for(int i = 0; i < NumLength(d); i++) {
        c *= 10;
    }
    cout << a + b + c + d;
}