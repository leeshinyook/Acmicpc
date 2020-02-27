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
vector<int> arr(1000002);

int T;
int MAX = 1, MIN = 1;
int len = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < T - 1; i++) {
        if(arr[i] <= arr[i + 1]) {
            len += 1;
            MAX = max(MAX, len);
        } else {
            len = 1;
        }
    }
    len = 1;
    for(int i = 0; i < T - 1; i++) {
        if(arr[i] >= arr[i + 1]) {
            len += 1;
            MIN = max(MIN, len);
        } else {
            len = 1;
        }
    }
    if(MAX >= MIN) {
        cout << MAX;
    } else {
        cout << MIN;
    }
}
