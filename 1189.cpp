#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;

int arr[6][6];
int R, C, K;
bool checker[6][6];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;
void search(int x, int y, int dist) {

    if(x == 0 && y == C - 1) {
        if(dist == K) {
            ans++;
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(0 <= nx && nx < R && 0 <= ny && ny < C) {
            if(!checker[nx][ny] && arr[nx][ny] == 0) {
                checker[nx][ny] = true;
                search(nx, ny, dist + 1);
                checker[nx][ny] = false;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            char x;
            cin >> x;
            if(x == '.') {
                arr[i][j] = 0;
            } else if(x == 'T') {
                arr[i][j] = 1;
            }
        }
    }
    checker[R - 1][0] = true;
    search(R - 1, 0, 1);
    cout << ans;


}
