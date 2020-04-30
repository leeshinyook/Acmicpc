#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M, K;
int ans = 0;
int cnt;
void DFS(int x, int y) {
    cnt++;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(visited[mx][my]) continue;
        if(mx < 1 || mx > N || my < 1 || my > M) continue;
        if(!arr[mx][my]) continue;
        DFS(mx, my);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] && !visited[i][j]){
                cnt = 0;
                DFS(i, j);
                if(ans < cnt) ans = cnt;
            }
        }
    }
    cout << ans;

}
