//
// Created by 이신육 on 2020-02-05.
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>

#define RANGE 501
using namespace std;

int arr[RANGE][RANGE];
bool visited[RANGE][RANGE];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
int cnt = 0, area_cnt = 0, MAX = 0;
void DFS(int x, int y) {
    visited[x][y] = true;
    area_cnt++;
    if(MAX < area_cnt) {
        MAX = area_cnt;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(1 <= nx && nx <= N && 1 <= ny && ny <= M) {
            if(arr[nx][ny] && !visited[nx][ny]) {
                DFS(nx, ny);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(!visited[i][j] && arr[i][j]) {
                DFS(i, j);
                area_cnt = 0;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    cout << MAX << '\n';

}
