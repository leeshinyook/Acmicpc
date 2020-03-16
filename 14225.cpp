#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

set<int> s;
vector<int> v;
int N;
void search(int idx, int sum) {
    if(idx >= N) return;

    sum += v[idx];
//    cout << sum << " ";
    s.insert(sum);

    search(idx + 1, sum - v[idx]);
    search(idx + 1, sum);
}
int main() {
      cin >> N;
      for(int i = 0; i < N; i++) {
          int num;
          cin >> num;
          v.push_back(num);
      }
      search(0, 0);
      int num = 0;
      s.insert(0);
      for(auto x : s) {
          if(num != x) {
              cout << num;
              return 0;
          }
          num++;
      }
      cout << num;
}