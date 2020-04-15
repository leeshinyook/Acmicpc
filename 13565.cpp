#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int arr[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[1001][1001];
int N, M;
bool ans;
void DFS(int x, int y) {
//    cout << a << b << '\n';
    visited[x][y] = true;
    if(x == N) {
        ans = true;
        return;
    };
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(mx < 1 || mx > N || my < 1 || my > M) continue;
        if(arr[mx][my] == 1) continue;
        if(visited[mx][my]) continue;
        visited[mx][my] = true;
        DFS(mx, my);
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1;i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for(int i = 1; i <= N; i++) {
            DFS(1, i);
    }
    if(ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}