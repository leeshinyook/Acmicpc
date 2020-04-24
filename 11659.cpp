#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#define DES 1000000;
using namespace std;

int N, M;
int arr[100001];
int dp[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }
};
