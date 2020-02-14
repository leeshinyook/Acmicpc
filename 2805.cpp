//
// Created by 이신육 on 2020-02-05.
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>


using namespace std;

int N, M; // 나무의 수, 나무의 길이
long long L, R;
long long Max = 0;
long long ans = 0;
vector<long long> tree(1000001);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> tree[i];
        if(Max < tree[i]) Max = tree[i];
    }
    L = 0;
    R = Max;

    while(L <= R) {
        long long mid = (L + R) / 2;
        long long total = 0;
        for(int i = 0; i < N; i++) {
            if(mid < tree[i])
                total += tree[i] - mid;
        }
        if(total >= M) {
            if(ans < mid)
                ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << ans;

}
