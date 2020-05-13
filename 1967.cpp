#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;

vector<pair<int, int>> v[10001];
int N, last;
bool visited[10001];
int sum = 0;
int ans = 0, maxIdx;
void DFS(int s, int dist) {
    visited[s] = true;
    for(auto x : v[s]) {
        if(visited[x.first]) continue;
        visited[x.first] = true;
        DFS(x.first, dist + x.second);
        visited[x.first] = false;
    }
    if(dist > ans) {
        ans = dist;
        maxIdx = s;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        last = a;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    DFS(maxIdx, 0);
    cout << ans;


}

