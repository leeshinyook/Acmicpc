#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int dp[11];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i < 11; i++) {
        int mid = i / 2;
        dp[i] = (i - mid) * mid + dp[i - mid] + dp[mid];
    }
    int N;
    cin >> N;
    cout << dp[N];
}