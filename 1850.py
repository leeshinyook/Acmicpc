import sys
from math import gcd
a, b = map(int, input().split())
for i in range(int(gcd(a, b))):
    print(1, end='')