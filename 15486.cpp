#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dp[1500001];
int t[1500001];
int p[1500001];
int N, ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }
    for(int i = N; i >= 1; i--) {
        if(i + t[i] > N + 1) dp[i] = dp[i + 1];
        else {
            dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
        }
    }
    cout << dp[1];


}