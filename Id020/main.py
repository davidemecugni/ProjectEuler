import math
total = 0 
#Adds all the digits of 100!
for digit in str(math.factorial(100)):
    total += int(digit)
print(f"The sum of the digit is : {total}")