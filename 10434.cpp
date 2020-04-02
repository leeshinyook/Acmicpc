#include <iostream>
#include <set>
using namespace std;

int N;
set<int> st;
int mat[10001];
bool checker;
void erathos() {
    for(int i = 1; i <= 10000; i++) {
        mat[i] = i;
    }
    for(int i = 2; i <= 10000; i++) {
        if(mat[i] == 0) continue;
        for(int j = i + i; j <= 10000; j += i) {
            mat[j] = 0;
        }
    }
}
void Search(int x) {
    int sum = 0;
    if(x == 1) return;
    while(x) {
        int temp = x % 10;
        sum += temp * temp;
        x /= 10;
    }
    if(st.count(sum)) {
        checker = true;
        return;
    }
    st.insert(sum);
    Search(sum);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, number;
    erathos();
    mat[1] = 0;

    cin >> T;
    for(int i = 1; i <= T; i++) {
        st.clear();
        checker = false;
        cin >> number >> N;
        cout << number << " " << N;
        Search(N);
        if(checker || !mat[N]) {
            cout << " NO\n";
        } else if(!checker && mat[N]){
            cout << " YES\n";
        }
    }


}