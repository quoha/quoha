#include "local.h"

Chunk *BufferToChunk(Buffer *b) {
	char *p         = b->data;
	char *endOfData = b->data + b->length;

	Chunk *head = 0;
	Chunk *tail = 0;

	while (p < endOfData) {
		int   type;
		char *startOfChunk = p;
		if (*p == '[' && *(p+1) == '[') {
			type = CHKTYPE_CODE;
			while (p < endOfData) {
				if (*p == ']' && *(p+1) == ']') {
					break;
				}
				++p;
			}
		} else {
			type = CHKTYPE_TEXT;
			while (p < endOfData) {
				if (*p == '[' && *(p+1) == '[') {
					break;
				}
				++p;
			}
		}
		char *endOfChunk = p;

		if (type == CHKTYPE_CODE) {
			startOfChunk += 2;
			if (p < endOfData) {
				p += 2;
			}
		}

		Chunk *c = (Chunk *)malloc(sizeof(Chunk) + sizeof(char) * (endOfChunk - startOfChunk));
		if (!c) {
			perror("Chunk.New");
			exit(2);
		}

		c->type   = type;
		c->length = endOfChunk - startOfChunk;
		memcpy(c->data, startOfChunk, c->length);
		c->data[c->length] = 0;

		if (head == 0) {
			head = tail = c;
		} else {
			tail->next = c;
			c->prev = tail;
			tail = c;
		}
		c->next = 0;
	}

	return head;
}
