#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//Returns the nth prime, not the fastest algo
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
//Finds the sum of primes before n
//ex. (10) -> 2+3+5+7 = 17
uint64_t SumOfPrimesBeforeN(uint64_t n) {
	//Includes the 2,3,5 so that we can skip those multiples
	uint64_t sum_of_primes = 10;
	for (uint64_t i=7; i < n ; i+=2) {
		if (IsPrime(i)) {
			sum_of_primes += i;
		}
	}
	return sum_of_primes;
}
//Prints the sum of all prime numbers before 2000000
int main(void) {
	printf("%I64u\n", SumOfPrimesBeforeN(2000000));
	return 0;
}