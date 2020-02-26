#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;

long long T, rem = 1;
int main() {
    cin >> T;
    for(int i = 2; i <= T; i++) {
        rem *= i;
        rem %= 1000000000000;
        while(rem % 10 == 0) {
            rem /= 10;
        }
    }
    cout << rem % 10;
}
