#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include "string"
using namespace std;
int N, M;
map<string, int> wear;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--) {
        wear.clear();
        int ans = 1;
        cin >> M;
        for(int i = 0; i < M; i++) {
            string name, position;
            cin >> name >> position;
            if(wear[position]) {
                wear[position]++;
            } else {
                wear[position] = 1;
            }
        }
        for(auto x : wear){
            ans *= (x.second + 1);
        }
        cout << ans - 1 << '\n';
    }



}
