#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;
int N;
int alphabet[26] = {0,};
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            alphabet[s[j] - 65] += (int)pow(10, s.length() - j - 1);
        }
    }
    int ans = 0;
    vector<int> v;
    for(int i = 0; i < 26; i++) {
        if(alphabet[i]) {
            v.push_back(alphabet[i]);
        }
    }
    int cnt = 9;
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < v.size(); i++) {
        ans += v[i]*cnt;
        cnt--;
    }
    cout << ans;
}
