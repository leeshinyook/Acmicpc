#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int> > > pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while(N--) {
        int num;
        cin >> num;
        if(num == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        } else {
            pq.push(make_pair(abs(num), num));
        }
    }
};
