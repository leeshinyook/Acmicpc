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
using namespace std;

int N, M;
int arr[501][501];
void Floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][k] && arr[k][j]) {
                    arr[i][j] = 1;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            arr[i][j] = 0;
        }
    }
    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    Floyd();
    int ans = 0;
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(i != j) {
                cnt += arr[i][j] + arr[j][i];
            }
        }
        if(cnt == N - 1) ans++;
    }
    cout << ans;

}
