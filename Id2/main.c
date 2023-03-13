#include <stdio.h>
unsigned long long fib(long long n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return fib(n-1)+fib(n-2);
}
int main(void) {
	unsigned long long sum = 0;
	int i = 0;
	while(fib(i)<4000000){
		if (fib(i) % 2 == 0) {
			sum += fib(i);
		}
		i++;
	}
	return 0;
}
