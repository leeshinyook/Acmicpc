#include <iostream>
#include <vector>

using namespace std;

// 소수 구하는 최강 알고리즘 에라토스테네스의 체

// 2부터 120까지 모든 소수를 구한다고 생각한다면,
// 2부터 120까지 모두 배열에 넣어버린뒤, 소수가 아닌것들을 모두 체크해버린다.
// 1. 2를 제외한 모든 2의 배수를 체크한다.
// 2. 3을 제외한 모든 3의 배수를 체크한다.
// 3. 5를 제외한 모든 5의 배수를 체크한다.
// 위와 동일.

// 즉, 체크가 안된 수들이 소수이다.


int main() {

    int start, end;
    cin >> start >> end;
    vector<long long> v(end + 1); // 벡터크기 할당

    for(int i = 2; i <= end; i++) {
        v[i] = i; // 입력받은 수 만큼 배열에 모두음 초기화 해준다.
    }

    for(long long i = 2; i <= end; i++) {
        if(v[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다.
            continue;
        for(long long j = i + i; j <= end; j += i) { // i를 제외한 i의 배수들은 0으로 체크한다.
                v[j] = 0; // 아닌 곳에 0 할당
        }
    }
    for(long long i = start; i <= end; i++) {
        if(v[i]) cout << v[i] << "\n";
    }

    return 0;
}