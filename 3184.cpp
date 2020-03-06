#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
char arr[251][251];
bool visited[251][251];

int R, C;
int sheep, wolf;
int total_sheep = 0, total_wolf = 0;
void DFS(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int mx = dx[i] + x;
        int my = dy[i] + y;
        if(mx < 1 || mx > R || my < 1 || my > C) continue;
        if(visited[mx][my]) continue;
        if(arr[mx][my] != '#') {
            visited[mx][my] = true;
            if(arr[mx][my] == 'o') sheep++;
            if(arr[mx][my] == 'v') wolf++;
            arr[mx][my] = '1';
            DFS(mx, my);
        }
    }
}
void whoWin() {
    if(sheep > wolf) {
        total_sheep += sheep;
    } else if(sheep <= wolf) {
        total_wolf += wolf;
    }
    sheep = 0;
    wolf = 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> arr[i][j];
        }
    }
    DFS(9, 1);
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(!visited[i][j]) {
                DFS(i, j);
                whoWin();
            }

        }
    }
    cout << total_sheep << " " << total_wolf;
}
