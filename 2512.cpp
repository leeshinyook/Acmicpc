#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int N, M;
long long L, R;
long long Max = 0;
long long ans = 0;
int total = 0;
vector<long long> budget(10001);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> budget[i];
        if(Max < budget[i]) {
            Max = budget[i];
        }
    }
    cin >> M;
    L = 0;
    R = Max;
    while(L <= R) {
        long long mid = (L + R) / 2;
        for(int i = 0; i < N; i++) {
            if(mid >= budget[i]) {
                total += budget[i];
            } else {
                total += mid;
            }
        }
        if(total <= M) {
            if(ans < mid) ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
        total = 0;

    }
    cout << ans;
}