#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N;
int k = 2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N != 1) {
        if(N % k == 0) {
            cout << k << '\n';
            N /= k;
        } else {
            k++;
        }
    }
    return 0;
}
