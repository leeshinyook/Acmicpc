#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dp[1001];
int t[1001];
int p[1001];
int N, ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }
    for(int i = 1; i <= N + 1; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j]);
            if(j + t[j] == i)
                dp[i] = max(dp[i], dp[j] + p[j]);
        }
        if(ans < dp[i]) ans = dp[i];
    }
    cout << ans;


}