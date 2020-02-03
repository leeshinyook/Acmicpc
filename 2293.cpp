//
// Created by 0864h on 2020-01-14.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> dp(100001);
int arr[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j >= arr[i]) {
                dp[j] += dp[j - arr[i]];
            }
        }
    }
    cout << dp[K];

}