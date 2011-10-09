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

#ifndef Quoha_src_lib_qdjinn_qdjinn_H
#define Quoha_src_lib_qdjinn_qdjinn_H

/*****************************************************************************
 */
#define QUOHAPARSER_VER_MAJOR  0
#define QUOHAPARSER_VER_MINOR  1
#define QUOHAPARSER_VER_PATCH  0
#define QUOHAPARSER_VER_NAME   "00.001.0000"
#define QUOHAPARSER_VER_TAG    "alpha"
#define QUOHAPARSER_MAX_BUFSZ  (128 * 1024)

/*****************************************************************************
 */
typedef struct QState  QState;
typedef struct QParser QParser;
typedef struct QToken  QToken;
typedef struct QChunk  QChunk;
typedef struct QBStack QBStack;
typedef struct QBuffer QBuffer;

/*****************************************************************************
 */
struct QState {
	struct {
		int         major;
		int         minor;
		int         patch;
		const char *name;
		const char *tag;
	} version;
	QParser *qp;
};

/*****************************************************************************
 */
struct QParser {
	QBStack *qs;

  struct {
    int         major;
    int         minor;
    int         patch;
    const char *name;
    const char *tag;
  } version;
};

/*****************************************************************************
 */
struct QToken {
	int            column;
	int            line;
	const char    *source;
	unsigned char *data;
};

/*****************************************************************************
 * QChunks are handy ways of linking QBuffers together
 */
struct QChunk {
	QChunk  *prev;
	QChunk  *next;
	QBuffer *b;
	int      isCode;
};

/*****************************************************************************
 * QBStack allows us to push and pop buffers. it is a convenience for
 * the parser
 */
struct QBStack {
	int      curr;
	int      max;
	QBuffer *st[64];
};

/*****************************************************************************
 * the QBuffer is the memory allocation unit for the parser
 */
struct QBuffer {
	int   length;         // number of characters stored in the buffer
	char *currData;       // pointer to the current data
	char *endOfData;      // one character past the last data
	char *startOfData;    // actual start of the data
	char  data[2];        // may hold all of the data
};

/*****************************************************************************
 */
QBuffer *QBufferFromBuffer(QBuffer *qb, const char *chunkEnd, int forceNewLine);
QBuffer *QBufferFromFile(const char *fileName, int forceNewLine);
QBuffer *QBufferFromString(const char *string, int length, int forceNewLine);
QBuffer *QBufferFree(QBuffer *qb);

/*****************************************************************************
 */
QChunk  *QChunkFromBuffer(QBuffer *qb, const char *chunkStart, const char *chunkEnd);

/*****************************************************************************
 */
QBStack *QBStackNew(void);
QBStack *QBStackPush(QBuffer *qb);
QBuffer *QBStackTop(void);
QBuffer *QBStackPop(void);
QBStack *QBStackDelete(QBStack *qbs);

/*****************************************************************************
 */
QParser *QParserNew(void);
QParser *QParserBuffer(QBuffer *qb);
QParser *QParserFree(QParser *qp);

/*****************************************************************************
 */
int QParserSetBuffer(QParser *qp, unsigned char *buffer, int bufferLength);

/*****************************************************************************
 */
QToken *QParserNextToken(QParser *qp);

/*****************************************************************************
 */
const char  *QParserVersionName(QParser *qp);
const char  *QParserVersionTag(QParser *qp);
int          QParserVersionMajor(QParser *qp);
int          QParserVersionMinor(QParser *qp);
int          QParserVersionPatch(QParser *qp);


#endif
