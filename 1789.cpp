#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    int num = 1;
    long long sum = 0;
    while(1) {
        sum += num;
        if(sum > N) {
            num--;
            break;
        }
        num++;
    }
    cout << num;
}
