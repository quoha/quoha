#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName, const char *mode) {
	FILE *fp = fopen(fileName, mode);
	if (!fp) {
		perror(fileName);
		exit(2);
	}
	return fp;
}
