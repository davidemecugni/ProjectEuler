#Code execution time: 0.09439
from time import time 
start = time()
from decimal import *

#Checks for the largest common prefix  
def fractionToDecimal(numr, denr):
 
    # Initialize result
    res = ""
 
    # Create a map to store already seen
    # remainders. Remainder is used as key
    # and its position in result is stored
    # as value. Note that we need position
    # for cases like 1/6.  In this case,
    # the recurring sequence doesn't start
    # from first remainder.
    mp = {}
 
    # Find first remainder
    rem = numr % denr
 
    # Keep finding remainder until either
    # remainder becomes 0 or repeats
    while ((rem != 0) and (rem not in mp)):
 
        # Store this remainder
        mp[rem] = len(res)
 
        # Multiply remainder with 10
        rem = rem * 10
 
        # Append rem / denr to result
        res_part = rem // denr
        res += str(res_part)
 
        # Update remainder
        rem = rem % denr
 
    if (rem == 0):
        return ""
    else:
        return res[mp[rem]:]
getcontext().prec = 100
max = 0
max_n = 0
x = ""
for i in range(2,1000):
    if len(fractionToDecimal(1, i))> max:
        max= len(fractionToDecimal(1, i))
        max_n = i
    
print(f"Longest repeating sequence is {max} of the number 1/{max_n}")
print(f"Code execution time: {(time()-start):.5f}")
