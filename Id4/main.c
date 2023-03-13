#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Function to check if it is palindrome
bool isPalindrome(char* str) {
	return _stricmp(str, _strrev(_strdup(str)))==0;
}
int main(void) {
	char num[7]= "ciao";
	int max = 0;
	for (int f = 1; f < 1000; f++) {
		for (int s = 1; s < 1000; s++) {
			sprintf(num, "%d", s * f);
			if (isPalindrome(num) && ((s * f) > max)) {
				max = s*f;
			}
		}
	}
	printf("%i\n",max);
	return 0;
}

