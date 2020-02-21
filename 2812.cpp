//
// Created by 이신육 on 22/02/2020.
//
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    deque<char> dq;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        while (K && !dq.empty() && dq.back() < s[i])
        {
            dq.pop_back();
            K--;
        }
        dq.push_back(s[i]);
    }

    for (unsigned int i = 0; i < dq.size() - K; i++)
    {
        cout << dq[i];
    }
    cout << "\n";

    return 0;



}
