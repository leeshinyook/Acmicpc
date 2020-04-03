#include <iostream>
#include <climits>
using namespace std;

int coin;
int ans = 0;
int main() {
    cin >> coin;
    while(coin) {
        if(coin % 5 == 0) {
            cout << ans + coin / 5;
            return 0;
        } else {
            coin -= 2;
            ans += 1;
        }
    }
    if(coin == 0) {
        cout << ans;
    } else {
        cout << -1;
    }
}