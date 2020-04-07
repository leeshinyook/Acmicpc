#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v[501];
set<int> ans;
bool visited[501];
int N, M;
int cnt = 0;
void search(int s ,int depth) {
    if(depth > 2) return;
    visited[s] = true;
    for(auto u : v[s]) {
        if(visited[u]) continue;
        visited[u] = true;
        ans.insert(u);
        cnt++;
        search(u, depth + 1);
        visited[u] = false;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    search(1, 1);
    cout << ans.size();

}