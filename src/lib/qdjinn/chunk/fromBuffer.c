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

/*****************************************************************************
 * QChunkFromBuffer(qb, chunkStart, chunkEnd)
 *   splits QBuffer into alternating chunks of code and non-code
 * qb         buffer to create chunk from
 * isCode     if 0, assume we are starting with text
 *            if 1, assume we are starting with code
 * chunkStart text flagging start of a chunk
 * chunkEnd   text flagging end   of a chunk
 *
 * returns pointer to new QChunk
 */
QChunk *QChunkFromBuffer(QBuffer *qb, const char *chunkStart, const char *chunkEnd) {
	QChunk *head         = 0;
	QChunk *tail         = 0;
	int     forceNewLine = 0;

	if (qb && chunkStart && *chunkStart && chunkEnd && *chunkEnd) {
		int   lenEnd       = strlen(chunkEnd);
		int   lenStart     = strlen(chunkStart);
		char *endOfChunk;
		char *startOfChunk;

		while (qb->currData < qb->endOfData) {
			int isCode = strncmp(qb->currData, chunkStart, lenStart) == 0;

			if (isCode) {
				qb->currData += lenStart;

				startOfChunk = qb->currData;

				// go until we run out of buffer or find the chunkEnd
				//
				while (qb->currData < qb->endOfData) {
					if (strncmp(qb->currData, chunkEnd, lenEnd) == 0)
						break;
					++qb->currData;
				}

				endOfChunk = qb->currData;

				if (qb->currData != qb->endOfData)
					qb->currData += lenEnd;
			} else {
				startOfChunk = qb->currData;

				// go until we run out of buffer or find the chunkStart
				//
				while (qb->currData < qb->endOfData) {
					if (strncmp(qb->currData, chunkStart, lenStart) == 0)
						break;
					++qb->currData;
				}

				endOfChunk = qb->currData;
			}

			QChunk *c = (QChunk *)malloc(sizeof(QChunk));
			if (!c) {
				perror("QChunk.New");
				exit(2);
			}

			c->isCode = isCode;
			c->b      = QBufferFromString(startOfChunk, endOfChunk - startOfChunk, forceNewLine);
			if (!c->b) {
				perror("QChunk.Buffer");
				exit(2);
			}
			c->prev   = tail;
			c->next   = 0;

			if (head)
				tail->next = c;
			else
				head = tail = c;
			tail = c;
		}
	}

	return head;
}
