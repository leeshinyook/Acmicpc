#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <typeinfo>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;
int T, num;
int idx = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> num;
        if(maxHeap.size() > minHeap.size()) minHeap.push(num);
        else maxHeap.push(num);
        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
            int maxTop = maxHeap.top(), minTop = minHeap.top();
            maxHeap.pop(), minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
        }
        cout << maxHeap.top() << '\n';
    }
}