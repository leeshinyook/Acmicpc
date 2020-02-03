//
// Created by 이신육 on 2020-02-03.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<int> upDP(1001);
vector<int> downDP(1001);
int arr[1001];
int T, ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;


    for(int i = 1; i <= T; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= T; i++) {
        upDP[i] = 1;
        for(int j = 1; j <= i; j++) {
            if(arr[j] < arr[i]) {
                upDP[i] = max(upDP[i], upDP[j] + 1);
            }
        }
    }
    for(int i = T; i >= 1; i--) {
        downDP[i] = 1;
        for(int j = T; j >= i; j--) {
            if(arr[j] < arr[i]) {
                downDP[i] = max(downDP[i], downDP[j] + 1);
            }
        }
    }


    for(int i = 1; i <= T; i++) {
        ans = max(upDP[i] + downDP[i], ans);
    }
    cout << ans - 1;



}
