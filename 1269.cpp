#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
using namespace std;

set<int> setA, setB;
int A, B;
int ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    while(A--) {
        int num;
        cin >> num;
        setA.insert(num);
    }
    while(B--) {
        int num;
        cin >> num;
        setB.insert(num);
    }
    int cnt = 0;
    for(auto x : setA) {
        if(setB.count(x)) {
            cnt++;
        }
    }
    ans += setB.size() - cnt;
    cnt = 0;
    for(auto x : setB) {
        if(setA.count(x)) {
            cnt++;
        }
    }
    ans += setA.size() - cnt;
    cout << ans;
    return 0;
}
