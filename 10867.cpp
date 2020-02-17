//
// Created by 이신육 on 2020-02-05.
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <set>

using namespace std;

set<int> s;

int N;
long K;
int cnt = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> K;
        s.insert(K);
    }
    for(auto x : s) {
        cout << x << " ";
    }

}
