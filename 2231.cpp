#include <iostream>
using namespace std;

int TokenizedSum(int num) { // 각 자리수의 합
    int sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main() {
    int num;
    cin >> num;
    for(int i = 1; i <= num; i++) {
        if(i + TokenizedSum(i) == num) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}