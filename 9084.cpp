//#include <iostream>
//#include <climits>
#include <stdio.h>
//#include <queue>
//#include <cstring>
//#include <vector>
//#include <set>

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
        int i, j, t, n, m, a[21] = { 0 };
        scanf("%d", &t);
        while (t--) {
            scanf("%d", &n);
            for (i = 1; i <= n; i++) scanf("%d", &a[i]);

            scanf("%d", &m);
            int d[10001] = { 0 };

            d[0] = 1;
            for (i = 1; i <= n; i++)
                for (j = a[i]; j <= m; j++)
                    d[j] += d[j - a[i]];
            printf("%d\n", d[m]);
        }
}
