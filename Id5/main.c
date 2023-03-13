#include <stdio.h>
//Simple swap
void swap(long long* a, long long* b) {
	long long temp = *a;
	*a = *b;
	*b = temp;
}
//Euclidian algorithm for greatest common divider
long long gcd(long long a, long long b) {
	if (a < b) {
		swap(&a, &b);
	}
	while (a%b!=0) {
		a -= b;
		if (a < b) {
			swap(&a, &b);
		}
		
	}
	return b;
}
//Simple lowest common multiple
long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}
int main(void) {
	long long number = 1;
	for (long long i = 2; i < 21; i++) {
		//Number only multiplies the factors that
		//aren't already in the number
		number *= i / gcd(i, number);
	}
	printf("%u", number);
	return 0;
}