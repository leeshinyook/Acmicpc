#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b) {
    if(a.first < b.first) {
        return true;
    } else if(a.first == b.first){
        return false;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해
    int T;
    cin >> T;

    vector<pair<int,string>> v(T);

    for(int i = 0; i < T; i++) {
        cin >> v[i].first >> v[i].second;
    }
    stable_sort(v.begin(), v.end(), cmp);
    // 나이가 같은경우 sort는 순서를 보장하지않는 반면, stable_sort는 순서를 보장해준다.

    for(int i = 0; i < T; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}
