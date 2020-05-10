#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int N;
vector<int> arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int merge = arr[0] + arr[1];
    int res = arr[0] * arr[1];
    for(int i = 2; i < N; i++) {
        res += merge * arr[i];
        merge += arr[i];
    }
    cout << res;

}

