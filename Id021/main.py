#0.01787s to 0.00054s, 33 times faster than before
from time import time 

start = time()
#Find the sum of amicable numbers under 10000
#An amicable number is 220 bc SumDivisors(220)=284 and SumDivisors(284)=220
#Sum of the divisors of a given number without itself
#Ex. 10 -> 1 + 2 + 5 = 8
def SumDivisors(n):
    divisors = [1]
    for div in range(2, int(n**0.5)+1):
        if(n % div== 0):
            divisors.append(div)
            divisors.append(n//div)
    return sum(divisors)
total = 0
for i in range(1,10000):
    if( SumDivisors(SumDivisors(i)) == i and SumDivisors(i)!= i):
        total += i
print(f"The total is: {total}")
end = time()

print(f"Average code execution time: {((end - start)/100):.5f}")