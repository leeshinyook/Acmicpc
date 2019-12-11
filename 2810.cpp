#include <iostream>

using namespace std;

int main() {
    int couple = 0, cup = 0;
    bool couple_exist = false;
    int T;
    string str;
    cin >> T; // 그냥 관례적.
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'L') couple++;
        if(couple == 2) {
            cup++;
            couple = 0;
            couple_exist = true;
        }
        if(str[i] == 'S') cup++;
    }
    couple_exist ? cup++ : cup;
    cout << cup;

}