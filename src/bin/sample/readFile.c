#include "local.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

Buffer *ReadFile(const char *fileName) {
	struct stat statBuf;
	if (stat(fileName, &statBuf) != 0) {
		perror(fileName);
		exit(2);
	}

	Buffer *b = (Buffer *)malloc(sizeof(Buffer) + statBuf.st_size);
	if (!b) {
		perror("Buffer.New");
		exit(2);
	}
	b->length = statBuf.st_size;

	if (b->length == 0) {
		b->data[0] = 0;
		return b;
	}

	FILE *fp = fopen(fileName, "r");
	if (!fp) {
		perror(fileName);
		exit(2);
	}

	if (fread(b->data, b->length, 1, fp) != 1) {
		perror(fileName);
		exit(2);
	}

	fclose(fp);

	// force the buffer to end with a new-line
	char *lastChar = b->data + b->length - 1;
	if (*lastChar != '\n') {
		*(++lastChar) == '\n';
	}
	*(++lastChar) = 0;
		
	return b;
}
