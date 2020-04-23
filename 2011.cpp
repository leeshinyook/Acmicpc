#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000
using namespace std;

string N;
int v[5001];
int dp[5001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int LEN = N.length();
    for(int i = 1; i <= LEN; i++) {
        v[i] = N[i - 1] - '0';
    }
    if(LEN == 1 && N[0] == '0') {
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    for(int i = 1; i <= LEN; i++) {
        if(v[i] >= 1 && v[i] <= 9) {
            dp[i] = (dp[i - 1] + dp[i]) % mod;
        }
        if(i > 1) {
            int sum = v[i - 1] * 10 + v[i];
            if(sum >= 10 && sum <= 26) {
                dp[i] = (dp[i - 2] + dp[i]) % mod;
            }
        }
    }
    cout << dp[LEN];


}
