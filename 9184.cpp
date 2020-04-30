#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int a, b, c;
int dp[51][51][51];
void PrintFormat(int a, int b, int c) {
    cout << "w(" << a << ", " << b << ", " << c << ") = ";
}
int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if(dp[a][b][c] != 0) return dp[a][b][c];
    if(a < b && b < c) {
        return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
        return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        PrintFormat(a, b, c);
        cout << w(a, b, c) << '\n';
    }
    return 0;
}
