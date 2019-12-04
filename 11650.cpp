#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        if (a.second < b.second)
            return true;
    return false;

}


int main(void)
{
    int T;
    cin >> T;

    vector<pair<int, int>> v(T);

    for (int i = 0; i < T; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < T; i++)
        cout << v[i].first << " " << v[i].second << "\n";

    return 0;

}