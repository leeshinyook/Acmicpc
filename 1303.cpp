#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
char arr[101][101];
bool visited[101][101];
int N, M;
int wans = 0, bans = 0;
int DFS(int x, int y, int c) {
    int ret = 1;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(mx < 1 || mx > M || my < 1 || my > N) continue;
        if(visited[mx][my]) continue;
        if(arr[mx][my] == c) {
            ret += DFS(mx, my, c);
        }
    }
    return ret;
}
int main(void)
{
   cin >> N >> M;
   for(int i = 1; i <= M; i++) {
       for(int j = 1; j <= N; j++) {
           cin >> arr[i][j];
       }
   }
   for(int i = 1; i <= M; i++) {
       for(int j = 1; j <= N; j++) {
           if(visited[i][j]) continue;
           if(arr[i][j] == 'W') {
                int s = DFS(i, j, arr[i][j]);
                wans += s * s;
           } else if(arr[i][j] == 'B') {
               int s = DFS(i, j, arr[i][j]);
                bans += s * s;
           }
       }
   }
   cout << wans << " " << bans;
    return 0;
}