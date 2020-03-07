#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, K;
int cnt = 0;
int arr[100001];
int visited[100001];
int M = 98765432, ans = 0;
queue<pair<int, int>> q;

void BFS(int s) {
    q.emplace(s, 0);
    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        visited[x] = true;
        if(x > 100000) continue;
        if(x == K) {
            cnt++;
            if(dist <= M) {
                M = dist;
                ans++;
            }
        }
        if(0 <= x - 1 && !visited[x - 1]) {
            q.emplace(x - 1, dist + 1);
        }
        if(x + 1<= 100000 && !visited[x + 1]) {
            q.emplace(x + 1, dist + 1);
        }
        if(2 * x <= 100000 && !visited[2 * x]) {
            q.emplace(2 * x, dist + 1);
        }


    }

}
int main() {
    cin >> N >> K;
    BFS(N);
    cout << M <<'\n';
    cout << ans;
}