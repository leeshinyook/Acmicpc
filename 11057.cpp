#include <iostream>
#include <climits>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int dp[1001][10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i < 1001; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = j; k < 10; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum = (sum + dp[N][i]) % 10007;
    }
    cout << sum;
}