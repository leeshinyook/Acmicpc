dp = [0, 0, 1, 1, 3, 5]
for x in range(1000):
    dp.append(dp[-1] + dp[-2]*2)
n = int(input())
print(dp[n])