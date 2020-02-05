//
// Created by 이신육 on 2020-02-03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001][1001];
bool visited[1001];
int N, M;
int cnt = 0;
void DFS(int s) {
    visited[s] = true;
    for(int i = 1; i <= N; i++) {
        if(arr[s][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for(int i = 1; i <= N; i++) {
        if(!visited[i]){
            DFS(i);
            cnt++;
        }
    }
    cout << cnt;
}