#Code execution time: 0.04506
from time import time 
start = time()
res = 1
other_fib=1
i=2
#Finds the index of the first fib number 1000 digits long
while len(str(res))!=1000:
    prec = res
    res += other_fib
    other_fib = prec
    i+=1
    
print(f"The result is: {i}")
print(f"Code execution time: {(time()-start):.5f}")