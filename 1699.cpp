#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <typeinfo>
using namespace std;

vector<int> v(100001);
int T;
int idx = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for(int i = 1; i <= T; i++) v[i] = i;
    for(int i = 2; i <= T; i++) {
        for(int j = 2; j * j <= i; j++) {
            v[i] = min(v[i], v[i - j * j] + 1);
        }
    }
    cout << v[T];


}