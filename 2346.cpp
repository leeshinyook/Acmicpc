#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        v.push_back({ i + 1, num });
    }
    int idx = 0;
    int copyN = N;
    for (int i = 0; i < copyN; i++)
    {
        cout << v[idx].first << " ";

        int move = v[idx].second;
        if (move > 0)
            move--;
        v.erase(v.begin() + idx);
        idx += move;
        if (--N == 0)
            break;
        idx = (idx >= 0 ? idx : N + idx % N);
        idx %= N;
    }
    cout << "\n";
    return 0;

}
