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

vector<int> arr(1002);
vector<int> len(1002);
int T , ans = 0;
int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < T; i++) {
        len[i] = 1;
        for(int j = 0; j <= i; j++) {
            if(arr[j] < arr[i]) {
                len[i] = max(len[i], len[j] + 1);
            }
        }
    }
    for(int i = 0; i < T; i++) {
        ans = max(len[i], ans);
    }
    cout << ans;
}
