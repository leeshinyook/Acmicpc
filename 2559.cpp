#include <iostream>
#include <climits>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int N, K;
int sum = 0;
vector<int> v;
int dp[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i = 0; i < K; i++) {
        sum += v[i];
    }
    dp[0] = sum;
    int max = dp[0];
    for(int i = 1; i <= N - K; i++) {
        sum = dp[i - 1] - v[i - 1] + v[i + K - 1];
        dp[i] = sum;
        if(max < dp[i]) max = dp[i];
    }
    cout << max;
}