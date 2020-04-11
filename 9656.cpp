#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    if(T % 2) {
        cout << "CY";
    } else {
        cout << "SK";
    }
}