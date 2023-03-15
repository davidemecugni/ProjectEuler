#include <stdio.h>
#include <stdint.h>
//Tail recursive function to find the number of iterations
//To reach 1 in a Collatz path
uint32_t CollatzRecursive(uint32_t n, uint32_t iterations) {
	if (n == 1) {
		return iterations +1;
	}
	if (n % 2 == 0) {
		n /= 2;
	}
	else {
		n = 3 * n + 1;
	}
	return CollatzRecursive(n, iterations + 1);
}
int main(void) {

	uint32_t max_result=0, max_number=0, tmp;
	//Finds the biggest Collatz path for numbers under 1000000
	for (uint32_t i = 1; i < 1000000; i++) {
		tmp = CollatzRecursive(i, 0);
		if( tmp > max_result) {
			max_result = tmp;
			max_number = i;
		}
	}
	printf("%u\n", max_number);
	return 0;
}