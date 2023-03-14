#include <stdio.h>
#include <stdint.h>
//Simple algo to find the sum 1+2+...+n
uint64_t EulerSum(uint64_t n) {
	return (n * (n + 1)) / 2;
}
//Simple algo to find the sum of squares 1^2+2^2...
uint64_t SumOfSquares(uint64_t n) {
	uint64_t sum = 0;
	for (uint64_t i = 1; i < n + 1; i++) {
		sum += i * i;
	}
	return sum;
}
//Calculates the difference between ES^2-SoS
int main(void) {
	printf("%I64u\n", EulerSum(100)*EulerSum(100)-SumOfSquares(100));
	return 0;
}