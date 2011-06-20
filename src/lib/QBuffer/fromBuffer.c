/*****************************************************************************
 *  Quoha - a quaint framework for static websites
 *
 *  Copyright (C) 2011 Michael D Henderson
 *
 *  This file is part of Quoha (http://quoha.org).
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

/*****************************************************************************
 */
#include "local.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*****************************************************************************
 */
QChunk *QChunkFromBuffer(QBuffer *qb, const char *chunkStart, const char *chunkEnd) {
	char *p         = qb->startOfData;
	char *endOfData = qb->endOfData;

	QChunk *head = 0;
	QChunk *tail = 0;

	while (p < endOfData) {
		int   isCode;
		char *startOfChunk = p;
		if (strncmp(p, chunkStart, strlen(chunkStart)) == 0) {
			isCode = 1;
			p += strlen(chunkStart);
			while (p < endOfData) {
				if (strncmp(p, chunkEnd, strlen(chunkEnd)) == 0) {
					break;
				}
				++p;
			}
		} else {
			isCode = 0;
			while (p < endOfData) {
				if (strncmp(p, chunkStart, strlen(chunkStart)) == 0) {
					break;
				}
				++p;
			}
		}
		char *endOfChunk = p;

		if (isCode) {
			startOfChunk += strlen(startOfChunk);
			if (p < endOfData) {
				p += strlen(endOfChunk);
			}
		}

		QChunk *c = (QChunk *)malloc(sizeof(QChunk) + sizeof(char) * (endOfChunk - startOfChunk));
		if (!c) {
			perror("QChunk.New");
			exit(2);
		}

		c->isCode = isCode;

		c->buf = QBufferFromString(startOfChunk, endOfChunk - startOfChunk, 0);
		if (!c->buf) {
			perror("QChunk.NewBuffer");
			exit(2);
		}

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
