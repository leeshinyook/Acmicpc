#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <climits>
using namespace std;

deque<pair<long, long>> v;
long N;
bool cmp(pair<long, long> a, pair<long, long> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        long a, b;
        cin >> a >> b;
        if(a > b) {
            v.push_front({b, a});
        } else {
            v.push_front({a, b});
        }

    }
    sort(v.begin(), v.end(), cmp);


    long min = v.front().first;
    long max = v.front().second;
    v.pop_front();
    long ans = abs(max - min);
    int size = v.size();
    for (int i = 0; i < size; i++) {
        long x = v.front().first;
        long y = v.front().second;
        v.pop_front();

        if (min <= x && max >= x && max <= y) {
            ans += abs(max - y);
            max = y;
        } else if (max < x) {
            min = x;
            max = y;
            ans += abs(x - y);
        }
    }
    cout << ans;




}