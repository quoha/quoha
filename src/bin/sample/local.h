#ifndef local_H
#define local_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Buffer {
	int  length;
	char data[2];
};
typedef struct Buffer Buffer;

#define CHKTYPE_CODE 0x01
#define CHKTYPE_TEXT 0x00

struct Chunk {
	Chunk *prev;
	Chunk *next;
	int   type;
	int   length;
	char  data[1];
};
typedef struct Chunk Chunk;

struct Command {
	const char *name;
	int       (*func)(void);
};
typedef struct Command Command;

Chunk  *BufferToChunk(Buffer *b);
FILE   *OpenFile(const char *fileName, const char *mode);
Buffer *ReadFile(const char *fileName);

#endif
