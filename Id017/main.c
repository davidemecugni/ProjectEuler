#include <stdint.h>
#include <stdio.h>
//Returns the number of letters of the numbers 1-9
uint32_t UnitsToNumberOfLetters(uint32_t n) {
	switch (n) {
	case 1: return 3; break;
	case 2: return 3; break;
	case 3: return 5; break;
	case 4: return 4; break;
	case 5: return 4; break;
	case 6: return 3; break;
	case 7: return 5; break;
	case 8: return 5; break;
	case 9: return 4; break;
	default: return 0; break;
	}
}
//Returns the number of letters of the numbers 11-19
uint32_t Eleven_NineteenToNumberOfLetters(uint32_t n) {
	switch (n) {
	case 11: return 6; break;
	case 12: return 6; break;
	case 13: return 8; break;
	case 14: return 8; break;
	case 15: return 7; break;
	case 16: return 7; break;
	case 17: return 9; break;
	case 18: return 8; break;
	case 19: return 8; break;
	default: return 0; break;
	}
}
//Returns the number of letters of the tens 10-90
uint32_t TensToNumberOfLetters(uint32_t n) {
	switch (n) {
	case 10: return 3; break;
	case 20: return 6; break;
	case 30: return 6; break;
	case 40: return 5; break;
	case 50: return 5; break;
	case 60: return 5; break;
	case 70: return 7; break;
	case 80: return 6; break;
	case 90: return 6; break;
	default: return 0; break;
	}
}

//Returns the number of letters used in English to write the number 1-1000
uint32_t NumberToNumberOfLetters(uint32_t n) {
	if (n / 10 == 0) {
		return UnitsToNumberOfLetters(n);
	}
	if (n / 10 == 1 && n!= 10) {
		return Eleven_NineteenToNumberOfLetters(n);
	}
	if (n == 1000) {
		return 3 + 8;
	}
	uint32_t total = 0, tens, units;
	if ((n - (n / 100) * 100) == 0) {
		return UnitsToNumberOfLetters(n / 100) + 7;
	}
	if (n / 100) {
		total += UnitsToNumberOfLetters(n / 100) + 7 + 3; // + "hundred" + "and"
	}
	tens = (n - (n / 100) * 100) - n % 10;
	units = (n - (n / 100) * 100) - ((n - (n / 100) * 100) / 10) * 10;
	if (Eleven_NineteenToNumberOfLetters(n - (n / 100) * 100)) {
		total += Eleven_NineteenToNumberOfLetters(n - (n / 100) * 100);
		return total;
	}
	if (UnitsToNumberOfLetters(n - (n / 100) * 100)) {
		total += UnitsToNumberOfLetters(n - (n / 100) * 100);
		return total;
	}

	return total + TensToNumberOfLetters(tens) + UnitsToNumberOfLetters(units);
}

int main(void) {
	uint32_t total = 0;
	//Total of chars, without spaces, to write numbers 1-1000
	for (uint32_t i = 1; i < 1001; i++) {
		total += NumberToNumberOfLetters(i);
	}
	printf("%u", total);
	return 0;
}