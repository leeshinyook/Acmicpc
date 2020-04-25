#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;
vector<int> target;
queue<pair<vector<int>, int>> q;
set<vector<int>> s;
void BFS(vector<int> vp) {
    q.push({vp, 0});
    s.insert(vp);
    while(!q.empty()) {
        vector<int> x = q.front().first;
        int d = q.front().second;
        q.pop();
        if(target == x) {
            cout << d;
            return;
        }
        for(int i = 0; i <= v.size() - K; i++) {
            vector<int> cp = x;
            reverse(cp.begin() + i, cp.begin() + K + i);
            if(s.count(cp)) continue;
            s.insert(cp);
            q.push({cp, d + 1});
        }
    }
    cout << -1;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        target.push_back(num);
    }
    sort(target.begin(), target.end());
    BFS(v);
};
