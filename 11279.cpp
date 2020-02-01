#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <typeinfo>
#include <queue>

using namespace std;

priority_queue<long long> q;
int T;
int idx = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    long long cmd;
    while(T--) {
        cin >> cmd;
        if(!cmd) {
            if(!q.size()) {
                cout << 0 << "\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(cmd);
        }
    }
}