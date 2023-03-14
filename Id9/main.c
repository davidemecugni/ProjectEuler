#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
bool IsPythagoreanTriplet(unsigned int a, unsigned int b, unsigned int c) {
	return (a * a + b * b == c * c) ;
}
int main(void) {
	//Finds a*b*c s.t. a^2+b^2=c^2 && a+b+c == 1000
	for (unsigned int a = 1, c; a <= 500; a++) {
		for (unsigned int b = 1; b <= 500 && a + b <1001; b++) {
			c = 1000 - a - b;
			if (IsPythagoreanTriplet(a, b, c)) {
				printf("a,b,c : %u, %u, %u\n", a, b ,c);
				printf("%u\n", a * b * c);
				return 0;
			}
		}
	}
	return -1;
}