#include <iostream>

using namespace std;

int main() {
    int T, sum = 0;
    int num;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> num;
        sum += num;
    }
    cout << sum - (T - 1);

}