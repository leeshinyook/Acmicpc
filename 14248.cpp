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

int arr[100002];
bool visited[100002];
queue<int> q;
int N, start, cnt = 0;
int BFS(int x) {
    q.push(x);
    cnt++;
    visited[x] = true;
    while(!q.empty()) {
        int idx = q.front();
        int position[2] = {arr[idx], -1 * arr[idx]};
        q.pop();
        for(int i = 0; i < 2; i++) {
            if(idx + position[i] < 1 || idx + position[i] > N) continue;
            if(visited[idx + position[i]]) continue;
            visited[idx + position[i]] = true;
            cnt++;
            q.push(idx + position[i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> start;
    BFS(start);
    cout << cnt;
}

