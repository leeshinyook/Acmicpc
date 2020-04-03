#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> tmp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    while(true) {
        cin >> T;
        if(T == 0) return 0;
        while(!v.empty())v.pop_back();
        while(!tmp.empty())tmp.pop_back();
        for(int i = 0; i < T; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        for(int i = 0; i < 6; i++) {
            tmp.push_back(1);
        }
        for(int i = 0; i < T - 6; i++) {
            tmp.push_back(0);
        }

        do {
            for(int i = 0; i < T; i++) {
                if(tmp[i] == 1) cout << v[i] << " ";
            }
            cout << '\n';
        } while(prev_permutation(tmp.begin(), tmp.end()));
        cout << '\n';
    }

}