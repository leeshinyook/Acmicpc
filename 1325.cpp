#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[10001];
int visited[10001];
vector<int> cnt(10001);
int N, M;
int c = 0;
int DFS(int s) {
    visited[s] = true;
    for(auto u : v[s]) {
        if(!visited[u]) {
            c++;
            DFS(u);
        }
    }
}
int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        c = 0;
        DFS(i);
        cnt[i] = c;
        if(ans < cnt[i]) ans = cnt[i];
    }
    for(int i = 1; i <= N; i++) {
        if(ans == cnt[i]) cout << i << " ";
    }

}