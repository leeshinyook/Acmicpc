#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> v(1002);
vector<int> idx = {1, 3, 4};
int T;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    v[1] = false;
    v[2] = true;
    v[3] = false;
    v[4] = true;

    for(int i = 5; i <= 1001; i++) {
        for(int j = 0; j < 3; j++) {
            if(!v[i - idx[j]]) {
                v[i] = true;
                break;
            }
            v[i] = false;
        }
    }
    if(v[T]) {
        cout << "SK";
    } else {
        cout << "CY";
    }

}