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

#ifndef Quoha_src_lib_quohaparser_QuohaParser_H
#define Quoha_src_lib_quohaparser_QuohaParser_H

#define QUOHAPARSER_VER_MAJOR 0
#define QUOHAPARSER_VER_MINOR 1
#define QUOHAPARSER_VER_PATCH 0
#define QUOHAPARSER_VER_NAME  "00.001.0000"
#define QUOHAPARSER_VER_TAG   "alpha"

/*****************************************************************************
 */
struct QuohaParser {
  struct {
    int major;
    int minor;
    int patch;
    const char *name;
    const char *tag;
  } version;
};
typedef struct QuohaParser QuohaParser;

/*****************************************************************************
 */
QuohaParser *QuohaParserNew(void);
QuohaParser *QuohaParserFree(QuohaParser *qp);

/*****************************************************************************
 */
const char  *QuohaParserVersionName(QuohaParser *qp);
const char  *QuohaParserVersionTag(QuohaParser *qp);
int          QuohaParserVersionMajor(QuohaParser *qp);
int          QuohaParserVersionMinor(QuohaParser *qp);
int          QuohaParserVersionPatch(QuohaParser *qp);

#endif
