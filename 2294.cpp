#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int N, M;
vector<int> coin(101);
int dp[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        dp[i] = 100000;
    }

    for(int i = 1; i <= N; i++) {
        cin >> coin[i];
        for(int j = coin[i]; j <= M; j++) {
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    if(dp[M] == 100000) cout << -1;
    else cout << dp[M];

}