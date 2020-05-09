#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int N;
double MX = -987654321;
double arr[10001];
double dp[10001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for(int i = 1; i <= N; i++) {
        if(dp[i - 1] > 1) {
            dp[i] = dp[i - 1] * arr[i];
        } else {
            dp[i] = arr[i];
        }
    }
    for(int i = 1; i <= N; i++) {
        MX = max(MX, dp[i]);
    }
    printf("%.3lf", MX);
}