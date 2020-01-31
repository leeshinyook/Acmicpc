#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;
vector<pair<int, int>> unsorted(500001);
vector<pair<int, int>> sorted(500001);
int main() {
    FASTSTD;
    FASTCIN;
    int ans = 0;
    int T;
    cin >> T;
    vector<pair<int, int>> unsorted(T + 1);
    vector<pair<int, int>> sorted(T + 1);
    for(int i = 1; i <= T ;i++) {
        cin >> unsorted[i].first;
        unsorted[i].second = i;
        sorted[i].first = unsorted[i].first;
    }
    stable_sort(sorted.begin(), sorted.end());
    stable_sort(unsorted.begin(), unsorted.end());
    for(int i = 1; i <= T; i++) {
        sorted[i].second = i;
    }
    for(int i = 1; i <= T; i++) {
        int sub = unsorted[i].second - sorted[i].second;
        ans = max(ans, sub);
    }
    cout << ans + 1;

    return 0;
}