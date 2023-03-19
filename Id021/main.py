import math
#Find the sum of amicable numbers under 10000
#An amicable number is 220 bc SumDivisors(220)=286 and SumDivisors(286)=220
#Sum of the divisors of a given number without itself
#Ex. 10 -> 1 + 2 + 5 = 8
def SumDivisors(n):
    divisors = []
    for div in range(1, n//2 + 1):
        if(n % div== 0):
            divisors.append(div)
    return sum(divisors)
total = 0
for i in range(1,10000):
    if( SumDivisors(SumDivisors(i)) == i and SumDivisors(i)!= i):
        total += i
print(f"The total is: {total}")