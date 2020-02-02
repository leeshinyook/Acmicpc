#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <typeinfo>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> minHeap;
int T, num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> num;

        if(!num) {
            if(!minHeap.empty()) {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            } else {
                cout << 0 << '\n';
            }
        } else {
            minHeap.push(num);
        }
    }
}