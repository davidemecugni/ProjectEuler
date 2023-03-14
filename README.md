# ProjectEuler
First 100 ProjectEuler Problems
# What is a Project Euler Problem?
Project Euler is an online project that publishes math problems solvable by algorithms.
The challenge is providing the correct solution to the problem given. Such a problem could be:
## What is the 10 001st prime number?
A quick solution could be
```c
//Returns the nth prime, not the fastest algo
bool IsPrime(uint64_t n) {
	if (n == 2 || n == 3) {
		return true;
	}
	for (uint64_t i = 2; i <= n / 2 ; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
//Finds the nth prime es. (6)->13
uint64_t NthPrime(uint64_t n) {
	uint64_t primecounter = 0;
	uint64_t prime = 2;
	while (primecounter < UINT64_MAX) {
		if (IsPrime(prime)) {
			++primecounter;
		}
		if (primecounter == n) {
			return prime;
		}
		++prime;
	}
}
```
