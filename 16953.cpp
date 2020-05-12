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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b; cin >> a >> b;
    queue <pair<long, long>> q;
    q.push({ a,1 });
    while (!q.empty()) {
        long now = q.front().first;
        long count = q.front().second;
        q.pop();
        if (now == b) {
            cout << count;
            return 0;
        }
        if (now * 2 <= b) {
            q.push({ now * 2, count + 1 });
        }
        if (now * 10 + 1 <= b) {
            q.push({ now * 10 + 1, count + 1 });
        }
    }
    cout << -1;

}

