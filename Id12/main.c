#include <stdio.h>
#include <stdint.h>

//Works with numbers greater than 6
uint64_t NumberOfDivisors(uint64_t n) {
	//Includes 1 and n
	uint64_t nr_divisors = 0;
	for (uint64_t div = 2; (div - 1) * (div - 1) < n; div++) {
		if (n % div == 0) {
			++nr_divisors;
		}
	}
	return nr_divisors * 2 + 2;
}
int main(void) {
	uint64_t triangle_number = 28;
	for (uint64_t i = 8;; i++) {
		triangle_number += i;
		//The problem is the triangular number with more than 500 divisors
		if (NumberOfDivisors(triangle_number) > 500) {
			printf("%I64u\n", triangle_number);
			break;
		}
	}
	return 0;
}