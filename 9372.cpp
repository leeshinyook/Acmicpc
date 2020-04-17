#include <iostream>
#include <climits>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;


vector<int> v[1001];
bool visited[1001];
int N, M, TC;

int cnt = 0;
void Search(int a) {
    queue<int> q;
    q.push(a);
    visited[a] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto u : v[x]) {
            if(visited[u]) continue;
            visited[u] = true;
//            cout << u << " ";
            cnt++;
            q.push(u);
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TC;
    while(TC--) {
        cin >> N >> M;
        for(int i = 0; i < 1001; i++) {
            while(!v[i].empty()) v[i].pop_back();
        }
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ans = INT_MAX;
        for(int i = 1; i <= N; i++) {
            cnt = 0;
            Search(i);
            if(ans > cnt) ans = cnt;
            memset(visited, false, sizeof(visited));
        }
        cout << ans << '\n';
    }


}