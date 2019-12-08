#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 300000

using namespace std;
int main() {
    int num, count = 0;
    vector<int> v(MAX);

    //일단 소수를 만들어두자.
    for(int i = 2; i <= MAX; i++) {
        v[i] = i;
    }
    for(int i = 2; i <= MAX; i++) {
        if(v[i] == 0) continue;
        for(int j = i + i; j <= MAX; j += i) {
            v[j] = 0; //소수는 자기자신과 1로만 나눠지니 체크가 안 될 것이다.
        }
    }

    // 출력부분.
    while(1) {
        cin >> num;
        if(!num) break;
        for(int i = num + 1; i <= num * 2; i++) {
            if(v[i]) count++; // 0이 아닌 부분 즉, 소수것만 카운팅.
        }
        cout << count <<"\n";
        count = 0;
    }
    return 0;
}