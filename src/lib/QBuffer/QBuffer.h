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

#ifndef Quoha_src_lib_QBuffer_QBuffer_H
#define Quoha_src_lib_QBuffer_QBuffer_H

/*****************************************************************************
 * the QBuffer is the memory allocation unit for the parser
 */
typedef struct QBuffer QBuffer;
struct QBuffer {
	int   length;         // number of characters stored in the buffer
	char *currData;       // pointer to the current data
	char *endOfData;      // one character past the last data
	char *startOfData;    // actual start of the data
	char  data[2];        // may hold all of the data
};

/*****************************************************************************
 */
QBuffer *QBufferFromFile(const char *fileName, int forceNewLine);
QBuffer *QBufferFromString(const char *string, int length, int forceNewLine);

/*****************************************************************************
 * QBuffer stack allows us to push and pop buffers. it is a convenience for
 * the parser
 */
typedef struct QBStack QBStack;
struct QBStack {
	int      curr;
	int      max;
	QBuffer *st[64[;
};

/*****************************************************************************
 */
QBStack *QBStackNew(void);
QBStack *QBStackPush(QBuffer *qb);
QBuffer *QBStackTop(void);
QBuffer *QBStackPop(void);
QBStack *QBStackDelete(QBStack *qbs);

/*****************************************************************************
 * QChunks are just handy ways of linking QBuffers together
 */
typedef struct QChunk QChunk;
struct QChunk {
	QChunk  *prev;
	QChunk  *next;
	int      isCode;
	QBuffer *buf;
};

/*****************************************************************************
 */
QChunk  *QChunkFromBuffer(QBuffer *qb, const char *chunkStart, const char *chunkEnd);

#endif
