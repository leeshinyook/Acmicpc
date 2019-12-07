#include <iostream>

using namespace std;
int retSum(int a, int b) {
    return b - a;
}
int main() {
    int input, output;
    int max = 0, sum = 0;

    for(int i = 0; i < 4; i++) {
        cin >> output >> input;
        sum += retSum(output, input);
        if(max < sum) max = sum;
    }
    cout << max;

    return 0;
}