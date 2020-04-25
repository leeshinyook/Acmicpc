#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int ans = INT_MIN;
int L[21], J[21]; // 체력 , 기쁨
vector<int> v;
void DFS(int idx, int total, int health) {
    if(idx == N + 1) {
        if(health > 0) v.push_back(total);
        return;
    }
    DFS(idx + 1, total + J[idx], health - L[idx]);
    DFS(idx + 1, total, health);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> L[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> J[i];
    }
    DFS(1, 0, 100);
    sort(v.begin(), v.end());
    cout << v[v.size() - 1];
};
