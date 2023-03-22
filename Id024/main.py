#Code execution time: 0.74979
from itertools import permutations
from time import time 
start = time()
res = ""
for i in list(permutations(range(0,10)))[999999]:
    res += str(i)
print(f"The result is: {res}")
print(f"Code execution time: {(time()-start):.5f}")