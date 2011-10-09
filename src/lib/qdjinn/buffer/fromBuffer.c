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
 * QBufferFromBuffer(qb, chunkEnd, forceNewLine)
 *   splits QBuffer into chunk of text
 * qb            buffer to create new buffer from
 * chunkEnd      text flagging end of a chunk
 * forceNewLine  force buffer to terminate with newline
 *
 * returns pointer to new QBuffer
 */
QBuffer *QBufferFromBuffer(QBuffer *qb, const char *chunkEnd, int forceNewLine) {
	QBuffer *t = 0;

	if (qb) {
		char *startOfChunk = qb->currData;
		int  len           = (chunkEnd && *chunkEnd) ? strlen(chunkEnd) : 0;

		if (!len) {
			qb->currData = qb->endOfData;
		} else {
			// go until we run out of buffer or find the chunkEnd
			//
			while (qb->currData < qb->endOfData) {
				if (strncmp(qb->currData, chunkEnd, len) == 0)
					break;
				++qb->currData;
			}
		}

		char *endOfChunk = qb->currData;

		if (qb->currData != qb->endOfData)
			qb->currData += len;

		t = QBufferFromString(startOfChunk, endOfChunk - startOfChunk, forceNewLine);
	}

	return t;
}
