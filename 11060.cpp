#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp(3000, 1000);
int arr[1002];
int T;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> arr[i];
    }
    dp[1] = 0;
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= arr[i]; j++) {
            dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }
    }
    if(dp[T] == 1000) {
        cout << -1;
    } else {
        cout << dp[T];
    }

}