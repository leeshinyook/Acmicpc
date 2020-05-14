#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <stdio.h>
#include <set>
using namespace std;

int dp[45], i;
int input[45];
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    dp[1] = 1;
    for(i = 2; ~scanf("%1d", &input[i]); i++) {
        if(input[i]) dp[i] += dp[i - 1];
        if(input[i] + input[i - 1] * 10 > 9 && input[i] + input[i - 1] * 10 < 35) dp[i] += dp[i - 2];
    }
    printf("%d", dp[i - 1]);
    return 0;

}

