N = int(input())

zero = 0
one = 1

for i in range(N - 1):
    if i % 2:
        temp_zero = zero + one - 1
    else :
        temp_zero = zero + one
    temp_one = zero + one
    zero = temp_zero
    one = temp_one
print(zero)

