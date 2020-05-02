#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include "string"
#define mod 1000000000;
using namespace std;

int N, M;
long long dp[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= 1000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cin >> N;
    if(N == -1) {
        cout << 1 << '\n' << 1;
        return 0;
    } else if(N < -1) {
        N *= -1;
        if(N % 2 == 0) {
            cout << -1 << '\n' << dp[N];
        } else {
            cout << 1 << '\n' << dp[N];
        }
        return 0;
    } else {
        if(dp[N] > 0) cout << 1 << '\n' << dp[N];
        else if(dp[N] == 0) cout << 0 << '\n' << 0;
    }


}
