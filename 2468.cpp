#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, cnt = 0;

queue<pair<int, int>> q;
void BFS(int K, int a, int b) {
    q.push({a, b});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = dx[i] + x;
            int my = dy[i] + y;
            if(mx < 1 || mx > N || my < 1 || my > N) continue;
            if(visited[mx][my]) continue;
            if(arr[mx][my] <= K) continue;
            visited[mx][my] = true;
            q.push({mx, my});
        }
    }
}
void init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            visited[i][j] = false;
        }
    }
    while(!q.empty()) {
        q.pop();
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    int T = 101;
    int MAX = 0;
    while(T--) {
        int cnt = 0;

        init();
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(!visited[i][j] && arr[i][j] > T) {
                    cnt++;
                    BFS(T, i, j);
                }
            }
        }
        if(MAX < cnt) {
            MAX = cnt;
        }
    }
    cout << MAX;

}