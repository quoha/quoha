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

#ifndef Quoha_src_lib_QParser_QParser_H
#define Quoha_src_lib_QParser_QParser_H

#include "../QToken/QToken.h"

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
struct QParser {
  struct {
	unsigned char *start;
	unsigned char *end;
	unsigned char *next;
  } data;
  struct {
    int major;
    int minor;
    int patch;
    const char *name;
    const char *tag;
  } version;
};
typedef struct QParser QParser;

/*****************************************************************************
 */
QParser *QParserNew(void);
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
