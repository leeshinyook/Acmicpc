//
// Created by 이신육 on 19/02/2020.
//
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

stack<int> s;
queue<char> oper;
bool inserted[100001];

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
      cin >> N;
      for(int i = 0; i < N; i++) {
          int num;
          cin >> num;

          if(!inserted[num]) {
              for(int j = 1; j <= num; j++) {
                  if(!inserted[j]) {
                      s.push(j);
                      oper.push('+');
                      inserted[j] = true;
                  }
              }
              if(s.top() != num) {
                  cout << "NO";
                  return 0;
              }
              s.pop();
              oper.push('-');
          } else {
              if(s.top() != num) {
                  cout << "NO";
                  return 0;
              }
              s.pop();
              oper.push('-');
          }
      }
      int size = oper.size();
      for(int i = 0; i < size; i++) {
          cout << oper.front() << '\n';
          oper.pop();
      }
}
