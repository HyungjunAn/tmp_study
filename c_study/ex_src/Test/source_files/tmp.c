#include <stdio.h>

int main() {
	int i;
	int j;

	for (i = 1; i <= 5; ++i) {
		for (j = 1; j <= 5 - i; ++j) {
			printf(" ");
		}
		for (j = 1; j <= i; ++j) {
			printf("%d", 5 - j + 1);
		}
		printf("\n");
	}
	return 0;
}
