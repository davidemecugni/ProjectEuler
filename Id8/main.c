#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint64_t DigitToUint64_t(char c) {
	switch (c) {
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case '0': return 0; break;
	default: return UINT64_MAX;
	}
}
//Finds the product of the digits in a string
//Es. "123" -> 1*2*3
uint64_t ProductOfDigits(char *str) {
	uint64_t prod = 1;
	for (size_t i = 0; i < strlen(str); i++) {
		prod *= DigitToUint64_t(str[i]);
		if (prod == 0) {
			return 0;
		}
	}
	return prod;
}
//Finds the biggest product of digits of
//lenght long substring in str
uint64_t MaxProductOfSubstring(char* str, size_t lenght) {
	size_t  nSubstrings = strlen(str) - lenght + 1;
	uint64_t max = 0;
	char* testedString = calloc(lenght + 1, sizeof(char));
	if (testedString == NULL) {
		return UINT64_MAX;
	}
	for (size_t i = 0; i < nSubstrings; i++) {
		memcpy(testedString, str + i, lenght);
		if (ProductOfDigits(testedString) > max) {
			max = ProductOfDigits(testedString);
		}
	}
	free(testedString);
	return max;
}
int main(void) {
	//Given string(len=1000) 
	char *givenString = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	//Finds the greatest product of 13 adjacent digits in givenString
	printf("%I64u", MaxProductOfSubstring(givenString,13));
	return 0;
}