#include <iostream>
using namespace std;
const int MAX = 20;
int N, S;
int arr[MAX];
int result = 0;

void numOfSubset(int idx, int sum) {
    sum += arr[idx];
    if (idx >= N)
        return;
    //조건 성립시
    if (sum == S)
        result++;
    //해당 숫자를 더하지 않는다.
    numOfSubset(idx + 1, sum - arr[idx]);
    //해당 숫자를 더한다.
    numOfSubset(idx + 1, sum);
}

int main(void) {
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    numOfSubset(0, 0);
    cout << result << endl;
    return 0;
}