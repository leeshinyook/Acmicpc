#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#define DES 1000000;
using namespace std;

int N;
int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        int ans = INT_MIN;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        dp[1] = arr[1];
        for(int i = 1; i <= N; i++) {
            dp[i] = arr[i];
            if(arr[i] + dp[i - 1] > dp[i]) {
                dp[i] = arr[i] + dp[i - 1];
            }
            if(ans < dp[i]) ans = dp[i];
        }
        cout << ans << '\n';
    }

}
