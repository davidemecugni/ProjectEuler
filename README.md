# ProjectEuler
First 100 ProjectEuler Problems
# What is a Project Euler Problem?
Project Euler is an online project that publishes math problems solvable by algorithms.
The challenge is providing the correct solution to the problem given in a reasonable computer time. Such a problem could be:
## What is the 10 001st prime number?
A quick implementation could be:
```c
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
bool IsPrime(uint64_t n) {
	//Optimised version
	
	//Excluded cases
	if (n == 0 || n == 1) {
		return false;
	}
	//Low primes
	if (n == 2 || n == 3 || n == 5) {
		return true;
	}
	
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
		return false;
	}
	//Every new prime number must be before or after 6
	//This is because every multiple of 2 or 3 is not a prime
	for (uint64_t i = 6; (i-1)*(i-1) <= n ; i+=6) {
		if (n % (i-1) == 0 || n % (i+1)==0) {
			return false;
		}
	}
	return true;
}
//Finds the nth prime es. (6)->13
uint64_t NthPrime(uint64_t n) {
	uint64_t primecounter = 0;
	uint64_t prime = 2;
	while (primecounter < UINT64_MAX) {
		if (IsPrime(prime)) {
			++primecounter;
		}
		if (primecounter == n) {
			return prime;
		}
		++prime;
	}
}
//Finds the 10001th prime
int main(void) {
	printf("%I64u\n", NthPrime(10001));
	return 0;
}
```
