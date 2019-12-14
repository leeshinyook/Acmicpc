//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//using namespace std;
//
//#define MAX 10000
//
//int main() {
//    int T, num, sub = MAX;
//    vector<int> v(MAX);
//    vector<int> prime;
//    pair<int, int> temp;
//    cin >> T;
//    for(int i = 2; i <= MAX; i++) {
//        v[i] = i;
//    }
//    for(int i = 2; i <= MAX; i++) {
//        if(v[i] == 0) continue;
//        for(int j = i + i; j <= MAX; j += i) {
//            v[j] = 0;
//        }
//    }
//    for(int i = 3; i <= MAX; i++) {
//        if(v[i]) prime.push_back(v[i]);
//    }
//    while(T){
//        cin >> num;
//        for(int i = 0; prime[i] < num; i++) {
//            for(int j = 0; prime[j] < num; j++) {
//                if(prime[i] + prime[j] == num && abs(prime[i] - prime[j]) <= sub) {
//                    temp.first = prime[j];
//                    temp.second = prime[i];
//                    sub = abs(prime[i] - prime[j]);
//                }
//            }
//        }
//        if(num == 4) {
//         temp.first = 2;
//         temp.second = 2;
//        }
//        sub = MAX;
//        cout << temp.first << " " << temp.second << "\n";
//        T--;
//    }
//}


#include <iostream>

using namespace std;

#define endl '\n'
#define fastio	ios_base::sync_with_stdio(0); cin.tie(0)

bool prime[10001];

int main() {
    fastio;

    int tc;	cin >> tc;

    memset(prime, true, sizeof(prime));

    for (int i = 2; i <= 10000; i++) {
        if (prime[i] == false)	continue;

        for (int j = i + i; j <= 10000; j += i) {
            prime[j] = false;
        }
    }

    while (tc--) {
        int n;	cin >> n;
        for (int i = n / 2; i > 1; i--) {
            int num1 = i;
            int num2 = n - i;
            if (prime[num1] && prime[num2] && n == num1 + num2) {
                cout << num1 << " " << num2 << endl;
                break;
            }
        }
    }
    return 0;
}