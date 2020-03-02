#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int arr[301][301];
int dp[301][301];

int N, M, T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] =  + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    cin >> T;

    while(T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
        cout << '\n';
    }

}
