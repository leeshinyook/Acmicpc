#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

long long dp[101];
int sum = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int N;
    cin >> N;
    int M;
    cin >> M;
    int temp = 0;
    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        sum *= dp[a - temp - 1];
        temp = a;
    }
    sum *= dp[N - temp];
    cout << sum;
};
