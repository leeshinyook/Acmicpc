#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

int arr[9][9];
int dx[8] = {1, 2, -1, -2, 1, 2, -1 , -2};
int dy[8] = {2, 1, 2, 1, -2, -1, -2, -1};
bool visited[9][9];
string INPUT;
int curX, curY, tarX, tarY;
queue<pair<pair<int, int>, int>> q;
void BFS(int a, int b) {
    q.push({{a, b}, 0});
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(x == tarX && y == tarY) {
            cout << dist;
            return;
        }
        for(int i = 0; i < 8; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx < 1 || mx > 8 || my < 1 || my > 8) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push({{mx, my}, dist + 1});
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 2; i++) {
        int x, y;
        cin >> INPUT;
        if(INPUT[0] == 'a') {
            x = 1;
        } else if(INPUT[0] == 'b') {
            x = 2;
        } else if(INPUT[0] == 'c') {
            x = 3;
        } else if(INPUT[0] == 'd') {
            x = 4;
        } else if(INPUT[0] == 'e') {
            x = 5;
        } else if(INPUT[0] == 'f') {
            x = 6;
        } else if(INPUT[0] == 'g') {
            x = 7;
        } else {
            x = 8;
        }
        char num = INPUT[1];
        y = num;
        y -= 48;
        if(i == 0) {
            curX = x, curY = y;
        } else if(i == 1) {
            tarX = x, tarY = y;
        }
    }
    BFS(curX, curY);



}