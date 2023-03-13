#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
	unsigned long long* v = calloc(1, sizeof(unsigned long long));
	int nFactors = 0, found =0;
	//Number given
	long long number = 600851475143;
	while (1) {
		for (unsigned long long i = 2; i <=  number; i++) {
			//If divisible, it saves the divider in the v array and updates the number of factors
			if (number % i == 0) {
				found = 1;
				v[nFactors] = i;
				number /= i;
				++nFactors;
				v = realloc(v, ((size_t)nFactors + 1) * sizeof(unsigned long long));
				break;
			}
		}
		if (!found) {
			break;
		}
		found = 0;
	}
	//It prints the last prime in the vector(it is the
	//biggest bc it's the last found
	printf("%u", v[nFactors-1]);
	free(v);
	return 0;
}