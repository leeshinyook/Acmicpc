#include<iostream>
#include<cmath>
using namespace std;

bool broken[10];

int N, M;
int result;
int check(int n) {
    if (n == 0) {
        if (broken[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (broken[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        broken[num] = true;
    }
    result = abs(100 - N);
    for(int i = 0; i <= 1000000; i++) {
        int num = i;
        int len = check(num);
        if(len) {
            int total = abs(num - N);
            if(result > total + len) {
                result = total + len;
            }
        }
    }
    cout << result;
}