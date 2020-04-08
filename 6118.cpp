#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> v[50001];
vector<int> dist(50001);
bool visited[50001];
int N, M;
queue<int> q;
void BFS(int s) {
    q.push(s);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto u : v[x]) {
            if(!dist[u]) {
                dist[u] = dist[x] + 1;
                q.push(u);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS(1);
    int MAX = INT_MIN;
    int cnt = 0;
    int locate = INT_MAX;
    for(int i = 2; i <= N; i++) {
        if(dist[i] > MAX) MAX = dist[i];
    }
    for(int i = 2; i <= N; i++) {
        if(dist[i] == MAX) {
            if(locate > i) locate = i;
            cnt++;
        }
    }
    cout << locate << " " << MAX << " " <<cnt;


}