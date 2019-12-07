#include <iostream>
#include <string>

// 문자열 처리
using namespace std;

int main() {
    int joi_count = 0, ioi_count = 0;
    string token;
    string str;
    cin >> str;

    for(int i = 0; i < str.length() - 2; i++) {
        token.push_back(str[i]);
        token.push_back(str[i + 1]);
        token.push_back(str[i + 2]);
        if (token == "JOI") joi_count++;
        if (token == "IOI") ioi_count++;
        token.pop_back();
        token.pop_back();
        token.pop_back();
    }
    cout << joi_count << endl;
    cout << ioi_count << endl;
}