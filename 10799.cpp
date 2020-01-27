//
// Created by leeshinyook on 2020-01-27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    string input;
    int sum = 0;
    cin >> input;
    for(int i = 0; i < input.length() - 1; i++) {
       if(input.at(i) == '(' && input.at(i + 1) == '(') {
           s.push(1);
       } else if(input.at(i) == ')' && input.at(i + 1) == ')') {
           sum += 1;
           s.pop();
       } else if(input.at(i) == '(' && input.at(i + 1) == ')') {
           sum += s.size();
       }

    }
    cout << sum;

}