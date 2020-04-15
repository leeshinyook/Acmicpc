#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int arr[6][6];
int visit[10000000];
int ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void DFS(int x, int y, int sum, int cnt) {
    if(cnt == 5) {
        if(visit[sum] == false) {
            visit[sum] = true;
            ans++;
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > 5 || ny < 1 || ny > 5) continue;
        DFS(nx, ny, sum * 10 + arr[ny][nx], cnt + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            DFS(i, j, arr[i][j], 0);
        }
    }
    cout << ans;

}