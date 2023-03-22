#Average Time 0.59501
from time import time 
#Returns if a number is abundant according to the definition
def IsAbundant(n):
    divisors = [1]
    for div in range(2, int(n**0.5)+1):
        if(n % div== 0):
            divisors.append(div)
            if(n // div != div):
                divisors.append(n//div)
    return n<sum(divisors)
def SumOf2AbundantNumbers(abundant, n):
    #Every even number greater than 46 can be expressed as the sum of 2
    #Abundant numbers
    if(n%2== 0 and n > 46):
        return True
    for ab in abundant:
        if(n-ab in abundant):
            return True
        if(ab>n):
            return False

start = time()               
total = 0
abundant = set()
#28124 in the number given, because every number >28124 can be expressed as the sum of 2
#Abundant numbers
for i in range(12,28124):
    if(IsAbundant(i)):
        abundant.add(i)
for i in range(0,28124):
    if(SumOf2AbundantNumbers(abundant, i) == False):
        total += i
print(f"The total is: {total}")
print(f"Code execution time: {(time()-start):.5f}")