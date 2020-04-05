#include <iostream>
#include <vector>
#include <cstring>
using namespace std;



char arr[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;
void DFS(int x, int y) {
    visited[x][y]= true;
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(mx < 1|| mx > N || my < 1 || my > M) continue;
        if(visited[mx][my])continue;
        visited[mx][my] = true;
        if(arr[mx][my] == '#')
            DFS(mx, my);
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int TC;
    cin >> TC;
    while(TC--) {
        memset(visited, false, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        int cnt = 0;
        cin >> N >> M;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cin >> arr[i][j];
            }
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(!visited[i][j] && arr[i][j] == '#') {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}