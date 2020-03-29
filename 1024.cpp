#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int N, L;
int oneToN(int n) {
    return n * (n + 1) / 2;
}
int main() {
    cin >> N >> L;

    for(int i = L; i <= 100; i++) {
        if((N - oneToN(L - 1)) / L >= 0 && (N - oneToN(L - 1)) % L == 0) {
            int x = (N - oneToN(L - 1)) / L;
            for(int j = x; j < x + L; j++) cout << j << " ";
            return 0;
        }
        L++;
    }
    cout << -1;
}