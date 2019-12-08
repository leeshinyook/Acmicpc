#include <iostream>
#include <string>

using namespace std;
int main() {
    string str;
    int capital_letter = 0, small_letter = 0, number = 0, blank = 0;

    while(1) {
        getline(cin, str); // 문자열에 공백도 포함하여 입력받는다.
        if(str=="") break;
        for(int j = 0; j < str.length(); j++) {
            if(str[j] > 64 && str[j] < 91) {
                capital_letter++;
            } else if(str[j] > 96 && str[j] < 123) {
                small_letter++;
            } else if(str[j] > 47 && str[j] < 58) {
                number++;
            } else if(str[j] == ' ') {
                blank++;
            } else if(str[j] == EOF) break;
        }
        cout << small_letter << " " << capital_letter << " " <<number << " " << blank << "\n";
        capital_letter = 0;
        small_letter = 0;
        number = 0;
        blank = 0;
    }
}