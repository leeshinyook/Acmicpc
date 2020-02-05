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

vector<int> dp(120000,120000);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 1;

    for(int i = 8; i <= T; i++) {
        int min1 = min(dp[i - 1], dp[i - 2]);
        int min2 = min(dp[i - 5], dp[i - 7]);
        dp[i] = min(min1, min2);
        dp[i]++;
    }
    cout << dp[T];

}
