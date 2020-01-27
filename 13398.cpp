#include <iostream>

using namespace std;

int arr[100000];
int dp[100000][2];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, ans;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ans = arr[0];
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = arr[i];
        if( i == 0 ) continue;
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
        ans = max(ans, max(dp[i][1], dp[i][0]));
    }

    cout << ans;

    return 0;
}
