#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

bool Palindrome(string str) {
    for(long unsigned int i = 0; i < str.length(); i++) {
        if(str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int MIN = 9999999;
int main() {
    string str;
    cin >> str;
    string temp = "";
    int cnt = 0;
    string str_temp = str;
    for(long unsigned int i = 0; i < str.length(); i++) {
        if(Palindrome(str_temp)) {
            break;
        }
        str_temp = str;
        cnt++;
        temp += str[i];
        reverse(temp.begin(), temp.end());
        str_temp += temp;
        reverse(temp.begin(), temp.end());

    }

    cout << cnt + str.length();
}