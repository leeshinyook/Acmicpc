#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include "string"
using namespace std;
vector<pair<string, string>> v;
int N, M;
bool compare(pair<string, string> a, pair<string, string> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string group;
        int number;
        cin >> group;
        cin >> number;
        for(int j = 0; j < number; j++) {
            string member;
            cin >> member;
            v.push_back({group, member});
        }
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < M; i++) {
        string name;
        int n;
        cin >> name;
        cin >> n;
        if(n) {
            for(auto x : v) {
                if(x.second == name) {
                    cout << x.first << '\n';
                    break;
                }
            }
        } else {
            for(auto x : v) {
                if(x.first == name) {
                    cout << x.second << '\n';
                }
            }
        }
    }




}
