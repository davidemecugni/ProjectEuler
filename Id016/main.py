two_at_1000 = 2**1000
digits = len(str(two_at_1000))
res = 0
for i in range(digits):
    res += two_at_1000%10
    two_at_1000 //= 10
print(res)
