#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int dp[1001][1001] = { 0 };
int n, m;
int ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &dp[i][j]);
        }
    }
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i][j] != 0) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if(ans < dp[i][j]) ans = dp[i][j];
            }
        }
    }
    cout << ans * ans;
    return 0;
// scanf와 cin을 같이 쓰지말라.
}
