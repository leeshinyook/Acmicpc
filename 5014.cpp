#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define DES 1000000;
using namespace std;

queue<pair<int, int>> q;
bool visited[1000001];
int F, S, G, U, D;

int BFS(int s) {
    q.push({s, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        if(x == G) return dist;
        q.pop();
        if((x + U) <= F && !visited[x + U]) {
            visited[x + U] = true;
            q.push({x + U , dist + 1});
        }
        if((x - D) >= 1 && !visited[x - D]) {
            visited[x - D] = true;
            q.push({x - D, dist + 1});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    int ans = BFS(S);
    if(ans == -1) cout << "use the stairs";
    else cout << ans;
}
