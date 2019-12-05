#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
bool compare(string first, string second) {
    if(first.length() > second.length())
        return true;
    else if(first.length() == second.length()) {
        if(first > second) return true;
    }
    return false;
}
int main() {
    vector<string> str;
    int T;
    string strs;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> strs;
        str.push_back(strs);
    }
    sort(str.begin(), str.end(), compare);
    str.erase(unique(str.begin(), str.end()), str.end()); // 중복제거

    for(int i = str.size() - 1; i >= 0; i--) {
            cout << str[i] << endl;
    }

}