#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//Recursive template of the function
//Data is the triangle, rows are the levels of the piramid, path is the current path(0 for same col, 1 to go right), i is the current level
//cnt is the current sum, col is the current col, max is the best sum found, best path is the best path found, tot is the number of iterations
void FindPathRec(short data[15][15], size_t rows, bool* path, int i, int cnt, int col, unsigned* max, bool* best_path, int *tot) {
	//If we reach the end of the tree("leaves") or if the current branch is surely worst than
	//The best
	if ( i == rows || (rows - i) *99 + cnt < *max) {
		//If the solution found is better than the best one found before
		if (cnt > *max) {
			*max = cnt;
			memcpy(best_path, path, sizeof(bool) * rows);

		}
		*tot += 1;
		return;
	}
	//If the subset is correctecly formed
	//The subset is of dim k

	//Case path following the same col
	path[i] = 0;
	FindPathRec(data, rows, path, i + 1, cnt + data[i][col], col, max, best_path, tot);
	//Case path following the same col to the right
	path[i] = 1;
	FindPathRec(data, rows, path, i + 1, cnt + data[i][col], col +1, max, best_path, tot);
}
//Non-recursive template of the function
int FindPath(short data[15][15], size_t rows, bool* best_path) {
	unsigned max = 0;
	int tot = 0;
	bool* path = calloc(rows , sizeof(bool)); //0 for same col, 1 to go right
	FindPathRec(data, rows, path, 0, 0, 0, &max, best_path, &tot);
	free(path);
	printf("Tot: %d\n", tot);
	return max;
}
void PrintPath(short data[15][15], bool* path, int rows) {
	int col = 0;
	printf("%hu", data[0][0]);
	for (int i = 0; i < rows -1 ; i++) {
		if (path[i]) {
			++col;
		}
		printf(" -> %hu", data[i+1][col]);

	}
	for (int i = 0; i < 15; i++) {
		printf("%d ", path[i]);
	}
}
int main(void) {
	short data[15][15] = {
	{ 75},
	{ 95, 64},
	{ 17, 47, 82},
	{ 18, 35, 87, 10},
	{ 20, 04, 82, 47, 65},
	{ 19, 01, 23, 75, 03, 34},
	{ 88, 02, 77, 73, 07, 63, 67},
	{ 99, 65, 04, 28, 06, 16, 70, 92},
	{ 41, 41, 26, 56, 83, 40, 80, 70, 33},
	{ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
	{ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
	{ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
	{ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
	{ 63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
	{ 04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}};
	//Has to be implemented with a backtracking algo
	bool* best_path = calloc(15, sizeof(bool)); //0 for same col, 1 to go right
	printf("Max = %d\n", FindPath(data, 15, best_path));
	PrintPath(data, best_path, 15);
	free(best_path);
	return 0;
}